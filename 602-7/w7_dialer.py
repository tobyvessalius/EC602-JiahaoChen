# -*- coding: utf-8 -*-
# AUTHOR Yue Sun yuesun@bu.edu
# AUTHOR JiaHao Chen tobychen@bu.edu
# AUTHOR YuNing Qiu qiuyn@bu.edu
# AUTHOR XinRan Zhang zhangxr@bu.edu
"""
Created on Thu Oct 20 16:31:08 2016

@author: Yuning Qiu, Yue Sun
"""
import scipy.io.wavfile as wavfile

import time
from numpy import pi,cos,array,append,linspace
#from pylab import linspace
def dialer(file_name,frame_rate,phone,tone_time):
    fs = frame_rate
    t = linspace(0, tone_time, frame_rate*tone_time)
    x_n = list(phone)
    T = []
    for i in x_n:
        if i == '1':
            fre = cos(2*pi*697*t) + cos(2*pi*1209*t)
            T = append(T,fre,axis=0)
        if i == '2':
            fre = cos(2*pi*697*t) + cos(2*pi*1336*t)
            T = append(T,fre,axis=0)
        if i == '3': 
            fre = cos(2*pi*697*t) + cos(2*pi*1477*t)
            T = append(T,fre,axis=0)
        if i == '4':
            fre = cos(2*pi*770*t) + cos(2*pi*1209*t)
            T = append(T,fre,axis=0)
        if i == '5':
            fre = cos(2*pi*770*t) + cos(2*pi*1336*t)
            T = append(T,fre,axis=0)
        if i == '6':
            fre = cos(2*pi*770*t) + cos(2*pi*1477*t)
            T = append(T,fre,axis=0)
        if i == '7':
            fre = cos(2*pi*852*t) + cos(2*pi*1209*t)
            T = append(T,fre,axis=0)
        if i == '8':
            fre = cos(2*pi*852*t) + cos(2*pi*1336*t)
            T = append(T,fre,axis=0)
        if i == '9':
            fre = cos(2*pi*852*t) + cos(2*pi*1477*t)
            T = append(T,fre,axis=0)
        if i == '0':
            fre = cos(2*pi*941*t) + cos(2*pi*1336*t)
            T = append(T,fre,axis=0)
    wavfile.write(file_name,fs,T)
    return T



