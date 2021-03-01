import numpy as np
import cv2
import subprocess
import os

import matplotlib.pyplot as plt


class ColorCorrection:
    def __init__(self):
        self.inpaint_rows = np.load("inpaint_rows.npy")
        self.inpaint_cols = np.load("inpaint_cols.npy")
        self.inpaint_img = np.load("inpaint_img.npy")
        self.width = 1200
        self.height = 1600
        self.eq_low = (30, 30, 30)
        self.eq_high = (255, 220, 210)

    @staticmethod
    def apply_gamma(img, gamma_rgb):
        img_result = np.copy(img)
        for i in range(3):
            lut = 255 * np.power(np.linspace(0, 1, 256), gamma_rgb[i])
            lut[-2] = lut[-1]
            img_result[:, :, i] = lut[img_result[:, :, i]]
        return img_result

    def equalizer(self, img):
        img_float = img.astype(np.float32)
        img_result = np.zeros(img.shape, dtype=np.uint8)
        for i in range(3):
            delta = self.eq_high[i] - self.eq_low[i]
            img_channel = (img_float[:, :, i] - self.eq_low[i]) * 255 / delta
            img_result[:, :, i] = np.clip(img_channel, 0, 255).astype(np.uint8)
        return img_result

    def convert_yuv(self, filename_yuv, filename_rgb, equalize=True, inpaint=False):
        dat = np.fromfile(filename_yuv, dtype=np.uint8)
        height_raw = self.width
        width_raw = self.height
        img_raw = dat.reshape((height_raw, width_raw, 2))
        img = cv2.cvtColor(img_raw, cv2.COLOR_YUV2RGB_YUYV)
        img = cv2.rotate(img, cv2.ROTATE_90_CLOCKWISE)

        if equalize:
            img = self.equalizer(img)

        if inpaint:
            img = self.inpaint(img)

        img = cv2.cvtColor(img, cv2.COLOR_RGB2BGR)

        if filename_yuv.endswith(".jpg"):
            cv2.imwrite(filename_rgb, img, [int(cv2.IMWRITE_JPEG_QUALITY), 95])
        else:
            cv2.imwrite(filename_rgb, img)

    @staticmethod
    def set_tags(*filenames, make="Omnivision", model="OV2640", f_35mm=35):
        if len(filenames) == 0:
            return
        files_str = " ".join(filenames)
        cmd = "exiftool -overwrite_original -make={} -model={} -FocalLengthIn35mmFormat={} {}".format(make,
                                                                                                      model,
                                                                                                      f_35mm,
                                                                                                      files_str)
        pipe = subprocess.PIPE
        proc = subprocess.Popen(cmd, shell=True, stdin=pipe, stdout=pipe, stderr=pipe)
        proc.wait()
        err = proc.stderr.read().decode('unicode-escape')
        if err != "":
            raise RuntimeError(err)

    @staticmethod
    def resize_img(filename_in, filename_out, stride=2):
        img = cv2.imread(filename_in, cv2.IMREAD_UNCHANGED)
        height, width, _ = img.shape
        dst_size = (width // stride, height // stride)
        img_out = cv2.resize(img, dst_size, cv2.INTER_LANCZOS4)
        cv2.imwrite(filename_out, img_out, [int(cv2.IMWRITE_JPEG_QUALITY), 95])

    def inpaint(self, img, k_size=4):
        img_result = np.copy(img)
        img_valid = np.pad(~self.inpaint_img, ((k_size, k_size), (k_size, k_size)), mode='constant')

        for c in range(3):
            img_pad = np.pad(img_result[:, :, c], ((k_size, k_size), (k_size, k_size)), mode='constant')

            for i, j in zip(self.inpaint_rows, self.inpaint_cols):
                img_slice = img_pad[i:i+2*k_size+1, j:j+2*k_size+1]
                img_valid_slice = img_valid[i:i+2*k_size+1, j:j+2*k_size+1]
                mask = img_valid_slice > 0
                if np.sum(mask) == 0:
                    print("warning at {}, {}".format(i, j))
                    continue
                val_median = np.median(img_slice[mask])
                if val_median < 1e-3:
                    continue
                img_result[i, j, c] = np.mean(img_slice[mask])

        return img_result


if __name__ == "__main__":
    main_inpaint()

    corr = ColorCorrection()

    corr.convert_yuv("view/img.yuv", "view/img_corr.jpg")