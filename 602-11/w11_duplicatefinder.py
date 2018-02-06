# -*- coding: utf-8 -*-
"""
Created on Tue Nov 29 17:07:50 2016

@author: Toby Chen
"""

from os import listdir
import re
from skimage.io import imread
import numpy as np
from os import getcwd
import hashlib

data = {}
c = listdir(getcwd())
for i in c:
    if 'png' in i:
        data[i] = imread(i)

d = c(1)
print (d)