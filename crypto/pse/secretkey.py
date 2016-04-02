from math import asin, sin, cos, tan, log, pi

def csc(x):
    return 1/sin(x)

def cot(x):
    return 1/tan(x)

def secret_func(x):
    theta = asin(12/13)
    return -127/pi * log(abs(cot(x+theta)+csc(x+theta)))
