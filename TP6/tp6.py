#! /usr/bin/python3

from ctypes import *
import timeit
from PIL import Image

img1 = "img/Lenna.png"
img2 = "img/panda.png"
img3 = "img/signature.png"

image_libc = cdll.LoadLibrary("./lib/lib_img.so")

def create_img_c(size) :
    Pix_c = c_double * size[0]
    Img_c_line = Pix_c * size[1]
    Img_c = Img_c_line * size[2]
    return Img_c()

def convert_color_to_c(color) :
    Pix_c = c_double * len(color)
    ret = Pix_c()
    for k in range(len(color)) :
        ret[k] = float(color[k] / 255)
    return ret

def convert_img_c_to_img(img, img_c, size) :
    bitmap = img.load()
    for i in range(size[0]):
        for j in range(size[1]):
            bitmap[i, j] = int(img_c[i][j][0] * 255), int(img_c[i][j][1] * 255), int(img_c[i][j][2] * 255), int(img_c[i][j][3] * 255)

class Picture :

    def __init__(self, fp:str=None, img=None, img_c=None) :
        if img == None :
            self.img = Image.open(fp)
        else :
            self.img = img
        if self.img.getbands != ("R","G","B","A") :
            self.img = self.img.convert("RGBA")
        tab = self.img.getprojection()
        self.size = (len(tab[0]), len(tab[1])) 
        if img_c == None :
            self.img_c = create_img_c((4, self.size[0], self.size[1]))
            self.convert_bitmap_to_c()
        else :
            self.img_c = img_c

    def convert_bitmap_to_c(self) :
        bitmap = self.img.load()
        for i in range(self.size[0]):
            for j in range(self.size[1]):
                for k in range(len(self.img_c[i][j])):
                    self.img_c[i][j][k] = float(bitmap[i, j][k] / 255)

    def rebuild_image(self) :
        convert_img_c_to_img(self.img, self.img_c, self.size)

    def do_function(self, function) :
        function(self.img_c)
        self.rebuild_image()

    def enlarge_int(self, function, factor:int) :
        Pix = c_double * 4
        P_line = POINTER(Pix)
        img_c = POINTER(P_line)()
        function(byref(img_c), self.img_c, factor)
        ret = Image.new("RGBA", (self.size[0] * factor, self.size[1] * factor))
        convert_img_c_to_img(ret, img_c, (self.size[0] * factor, self.size[1] * factor))
        return Picture(img=ret, img_c=img_c)

    def enlarge_img(self, function, factor:float) :
        Pix = c_double * 4
        P_line = POINTER(Pix)
        img_c = POINTER(P_line)()
        f = c_double(factor)
        function(byref(img_c), self.img_c, f)
        ret = Image.new("RGBA", (int(self.size[0] * factor), int(self.size[1] * factor)))
        convert_img_c_to_img(ret, img_c, (int(self.size[0] * factor), int(self.size[1] * factor)))
        return Picture(img=ret, img_c=img_c)

    def reduce_img(self, function, factor:float) :
        Pix = c_double * 4
        P_line = POINTER(Pix)
        img_c = POINTER(P_line)()
        f = c_double(factor)
        function(byref(img_c), self.img_c, f)
        ret = Image.new("RGBA", (int(self.size[0] / factor), int(self.size[1] / factor)))
        convert_img_c_to_img(ret, img_c, (int(self.size[0] / factor), int(self.size[1] / factor)))
        return Picture(img=ret, img_c=img_c)

    def do_an_other_function(self, other, function) :
        if self.size != other.size :
            return None
        img_c = create_img_c((4, self.size[0], self.size[1]))
        function(img_c, self.img_c, other.img_c)
        ret = Image.new("RGBA", self.size)
        convert_img_c_to_img(ret, img_c, self.size)
        return Picture(img=ret, img_c=img_c)

    def replace_zone(self, xy, lib, color) :
        lib.replace_zone(self.img_c, xy[0], xy[1], convert_color_to_c(color))
        self.rebuild_image()

    def replace_similar(self, xy, lib) :
        lib.replace_similar(self.img_c, xy[0], xy[1])
        self.rebuild_image()

    def show(self, title=None) :
        self.img.show(title)

    def close(self) :
        self.img.close()
        
pict = Picture(img1)
pict2 = Picture(img1)
pict3 = Picture(img1)
pict4 = Picture(img1)
pict5 = Picture(img1)
pict6 = Picture(img1)
pict7 = Picture(img2)
pict8 = Picture(img1)
pict9 = Picture(img1)
pict10 = Picture(img1)
pict11 = Picture(img1)
pict12 = Picture(img3)
pict13 = Picture(img1)


pict.do_function(image_libc.level_of_grey_av)
pict2.do_function(image_libc.level_of_grey_clearness)
pict3.do_function(image_libc.level_of_grey_luminance)
pict4.do_function(image_libc.tresholding_black_white)
pict5.do_function(image_libc.more_red)
pict6.do_function(image_libc.very_more_green)
pict7.do_function(image_libc.degraded_red_blue_img)
pict8.do_function(image_libc.middle_light)
pict9.replace_zone((10,10), image_libc, [0,0,0,0])
pict10.replace_similar((100,100), image_libc)
pict11.do_function(image_libc.segmentation)
pict14 = pict8.do_an_other_function(pict7, image_libc.average)
pict15 = pict12.do_an_other_function(pict13, image_libc.encoding)
pict16 = pict13.enlarge_int(image_libc.enlargement_integer, 2)
pict17 = pict13.enlarge_img(image_libc.enlargement, 1.5)
pict18 = pict13.reduce_img(image_libc.reduction, 2)


pict.show("grey_av")
pict2.show("grey_clear")
pict3.show("grey_lumi")
pict4.show("thresholding_black_white")
pict5.show("more_red")
pict6.show("very_more_green")
pict7.show("degraded_blue_red")
pict8.show("middle_light")
pict9.show("replace_zone")
pict10.show("replace_similar")
pict11.show("segement")
pict14.show("average")
pict15.show("encoding")
pict16.show("enlarg_int")
pict17.show("enlarg_dble")
pict18.show("reduction")

pict14.close()
pict.close()
pict2.close()
pict3.close()
pict4.close()
pict5.close()
pict6.close()
pict7.close()
pict8.close()
pict9.close()
pict10.close()
pict11.close()
pict12.close()
pict13.close()
pict16.close()
pict17.close()
pict18.close()

pict15.do_function(image_libc.decoding)
pict15.show("decoding")
pict15.close()
