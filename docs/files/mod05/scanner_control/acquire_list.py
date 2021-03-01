import numpy as np
import os

import acquire
import img_correction

ip = "192.168.1.6"


def main_circle():
    global ip
    filename_fmt = "img_{}"

    N_az = 300
    az_1d = np.linspace(0, 360, N_az)
    el_1d = [7, ]

    az_list, el_list = np.meshgrid(az_1d, el_1d, indexing="ij")
    az_list = az_list.flatten()
    el_list = el_list.flatten()

    filename_list = []

    for i in range(N_az):
        filename_list.append(filename_fmt.format(i))

    acquire.acquire_list(az_list, el_list, filename_list,
                         r"data\circular",
                         r"data\circular\jpg",
                         ip)


def main():
    global ip
    filename_fmt = "img_{}_{}"

    N_az = 16
    N_el = 4
    az_1d = np.linspace(-55, 55, N_az)
    el_1d = np.linspace(10, 40, N_el)

    az_list, el_list = np.meshgrid(az_1d, el_1d, indexing="ij")
    az_list = az_list.flatten()
    el_list = el_list.flatten()

    filename_list = []

    for i in range(N_az):
        for j in range(N_el):
            filename = filename_fmt.format(i, j)
            filename_list.append(filename)

    acquire.acquire_list(az_list, el_list, filename_list,
                         r"data/demo/",
                         r"data/demo/jpg",
                         ip)


def main_around():
    global ip
    filename_fmt = "img_{}_{}"

    N_az = 20
    N_el = 5
    az_1d = np.arange(N_az) * 360.0 / N_az
    el_1d = np.linspace(5, 40, N_el)

    az_list, el_list = np.meshgrid(az_1d, el_1d, indexing="ij")
    az_list = az_list.flatten()
    el_list = el_list.flatten()

    filename_list = []

    for i in range(N_az):
        for j in range(N_el):
            filename = filename_fmt.format(i, j)
            filename_list.append(filename)
            # img_correction.convert_yuv("data/IC3D_scene4/"+filename+".yuv", "data/IC3D_scene4/jpg/"+filename+".jpg")

    acquire.acquire_list(az_list, el_list, filename_list,
                         r"data\pot",
                         r"data\pot\jpg",
                         ip,
                         fake_shoot=False)


def main_mpeg():
    global ip
    az_list = np.load(r"D:\Documents\office\R6\design\mpeg\az_list.npy")
    el_list = np.load(r"D:\Documents\office\R6\design\mpeg\el_list.npy")

    dir_yuv = r"data/MPEG/test4/"
    dir_jpg = r"data/MPEG/test4/jpg"

    n = len(az_list)

    filename_list = ["img_{:02d}".format(i) for i in range(n)]

    acquire.acquire_list(az_list, el_list, filename_list, dir_yuv, dir_jpg, ip)

    cam = acquire.CameraRequest(ip, True)
    cam.move(0, 10)


if __name__ == "__main__":
    # main()
    # main_circle()
    main_around()
    # main_mpeg()
