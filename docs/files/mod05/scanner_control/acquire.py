import requests
import numpy as np
import time
import math
import os
import glob
import tqdm
import time

import random


import img_correction


class CameraRequest:
    def __init__(self, ip, verbose=False):
        self.ip = ip
        self.fmt_status = "/status"
        self.fmt_move = "/move?az={:.2f}&el={:.2f}"
        self.fmt_set = "/set?led_on={:d}&motor_on={:d}"
        self.fmt_shoot = "/shoot"
        self.verbose = verbose

    def get_txt(self, page, verbose=False):
        url = "http://" + self.ip + page
        r = requests.get(url)
        txt = r.text
        if verbose:
            print("GET:", url)
        return txt

    def set(self, led_val=None, led_on=False, motor_on=True, settle=True):
        page = self.fmt_set.format(led_on, motor_on)
        if led_val is not None:
            page += "&led_val={:03d}".format(led_val)
        txt = self.get_txt(page, self.verbose)
        if txt != "OK":
            return False
        self.wait()
        if settle:
            time.sleep(1)
        return True
    
    def wait(self):
        txt = "BUSY"
        page = self.fmt_status
        while txt != "IDLE":
            time.sleep(0.25)
            txt = self.get_txt(page)

    def move(self, az, el):
        page = self.fmt_move.format(az, el)
        txt = self.get_txt(page, self.verbose)
        if txt != "OK":
            return False
        self.wait()
        return True

    def homing(self):
        txt = self.get_txt("/homing", self.verbose)
        if txt != "OK":
            return False
        self.wait()
        return True
    
    def shoot(self, filename, led_on=False):
        page = self.fmt_shoot.format(int(led_on))
        url = "http://" + self.ip + page
        r = requests.get(url, allow_redirects=True)
        if self.verbose:
            print("GET:", url)
        open(filename, 'wb').write(r.content)


# def main_circle():
#     dir_root = "data_cube2_UXGA"
#     filename_fmt = "img_{}.yuv"
#     ip = "10.32.1.51"
#
#     N_point = 50
#
#     theta = np.linspace(0, 2*math.pi, N_point)
#
#     az_list = 90 + 16*np.cos(theta)
#     el_list = 20 + 10*np.sin(theta)
#
#     cam = CameraRequest(ip, True)
#
#     corr = img_correction.ColorCorrection()
#
#     filename_list = []
#
#     # for i in range(N_point):
#     for i in [7]:
#         az = az_list[i]
#         el = el_list[i]
#         yuv_path = os.path.join(dir_root, filename_fmt.format(i))
#         cam.move(az, el)
#         cam.shoot(yuv_path)
#         filename_list.append(yuv_path)
#
#     print("Post-process...")
#     for filename_yuv in tqdm.tqdm(filename_list):
#         _, head = os.path.split(filename_yuv)
#         filename_png = os.path.join(dir_root, "jpg", head.replace(".yuv", ".jpg"))
#         corr.correct_img(filename_yuv, filename_png)


def acquire_list(az_list, el_list, name_list, dir_yuv, dir_rgb, ip, output_ext="jpg", fake_shoot=False):
    cam = CameraRequest(ip, True)

    rgb_path_list = []
    
    os.makedirs(dir_yuv, exist_ok=True)
    os.makedirs(dir_rgb, exist_ok=True)

    corr = img_correction.ColorCorrection()
    
    if not fake_shoot:
        cam.set(led_on=True)

    for az, el, img_name in zip(az_list, el_list, name_list):
        yuv_path = os.path.join(dir_yuv, img_name+".yuv")
        rgb_path = os.path.join(dir_rgb, img_name+"."+output_ext)
        cam.move(az, el)
        if fake_shoot:
            cam.set(led_on=True, settle=False)
            time.sleep(0.6)
            cam.set(led_on=False, settle=False)
            time.sleep(1.2)
        else:
            cam.shoot(yuv_path)
            corr.convert_yuv(yuv_path, rgb_path)
            rgb_path_list.append(rgb_path)

    if output_ext == "jpg":
        corr.set_tags(*rgb_path_list)
    
    if not fake_shoot:
        cam.set(led_on=False, settle=False)


def main():
    N_az = 10
    N_el = 4

    filename_fmt = "img_{}_{}"

    az_1d = np.arange(N_az) * 360/N_az
    el_1d = np.linspace(6, 43, N_el)

    az_list, el_list = np.meshgrid(az_1d, el_1d, indexing="ij")
    az_list = az_list.flatten()
    el_list = el_list.flatten()

    filename_list = []

    for i in range(N_az):
        for j in range(N_el):
            filename_list.append(filename_fmt.format(i, j))

    acquire_list(az_list, el_list, filename_list,
                 r"data\IC3D_cube",
                 r"data\IC3D_cube\jpg",
                 "10.32.1.51")

def main2():
    N_az = 10
    N_el = 4

    filename_fmt = "img_{}_{}"

    az_1d = np.arange(N_az) * 360/N_az
    el_1d = np.linspace(6, 43, N_el)
    
    az_step = az_1d[1] - az_1d[0]
    el_step = el_1d[1] - el_1d[0]
    
    az_1d += az_step/2.0
    el_1d = el_1d[:-1] + el_step/2.0
    
    az_list, el_list = np.meshgrid(az_1d, el_1d, indexing="ij")
    az_list = az_list.flatten()
    el_list = el_list.flatten()

    filename_list = []

    for i in range(N_az):
        for j in range(N_el-1):
            filename_list.append(filename_fmt.format(i, j))

    acquire_list(az_list, el_list, filename_list,
                 r"data\IC3D_scene2_alt",
                 r"data\IC3D_scene2_alt\jpg",
                 "10.32.1.51")



def main_repeat():
    az_target = 30.0
    el_target = 25.0
    az_dist = [8.0, 20.0]
    el_dist = [5.0, 10.0]

    az_list = []
    el_list = []
    filename_list = []
    for i in range(30):
        az_ran = az_dist[0]+random.random()*(az_dist[1]-az_dist[0])
        el_ran = el_dist[0]+random.random()*(el_dist[1]-el_dist[0])

        if random.random() > 0.5:
            az_ran *= -1

        if random.random() > 0.5:
            el_ran *= -1

        az_list.append(az_target+az_ran)
        el_list.append(el_target+el_ran)
        az_list.append(az_target)
        el_list.append(el_target)
        filename_list.append("ran_{:02d}".format(i))
        filename_list.append("pic_{:02d}".format(i))

    print(az_list)
    print(el_list)

    acquire_list(az_list, el_list, filename_list,
                 "exp_repeat",
                 "exp_repeat/jpg",
                 "10.32.1.51")


if __name__ == "__main__":
    main()
    # main2()
    # main_repeat()
    # main_circle()
