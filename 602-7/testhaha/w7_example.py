# -*- coding: utf-8 -*-
# AUTHOR Yue Sun yuesun@bu.edu
# AUTHOR JiaHao Chen tobychen@bu.edu
# AUTHOR YuNing Qiu qiuyn@bu.edu
# AUTHOR XinRan Zhang zhangxr@bu.edu
"""
Created on Fri Oct 21 13:28:41 2016

@author: sunyue
"""
from numpy import fft,array,linspace,zeros,append
from math import ceil
def loudest_band(music,frame_rate,bandwidth):
    "define the variable low and high f"
    global f_low
    global f_high
    "store the lowest f for loudest part"
    index = [0]
    "length of signal"
    x_fre = fft.fft(music)
    n = len(x_fre)
    frequency = linspace(0,frame_rate,n+1)
    "intervel between each two signal"
    "length of BW"
    n_bw = ceil(bandwidth*n/frame_rate)
    "Initial value of loudest part"
    sum_bw = (abs(x_fre[0:n_bw])**2).sum()
    "Interation of loudest part"
    i = 1
    for i in range(ceil(n/2)-n_bw):
        Sum = ((abs(x_fre[i:i+n_bw]))**2).sum()
        if Sum > sum_bw:
            sum_bw = Sum
            index[0] = i
    "locate the lowest boundary"
    a = index[0]
    "reconstruct the signal"
    x_filter = [0]*n
    x_filter[a:a+n_bw+1]=x_fre[a:a+n_bw+1]
    x_filter[-a-n_bw+n:-a+n+1]=x_fre[-a-n_bw+n:-a+n+1]
    C_loud = fft.ifft(x_filter)
    "determine the lowest and highest frequency"
    f_low = frequency[a]
    f_high = frequency[a+n_bw]
    return f_low,f_high,C_loud
    
    
    
    