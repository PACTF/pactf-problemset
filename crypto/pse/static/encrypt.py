#!/usr/bin/python3

from secretkey import secret_func

import math

def s(f, x, precision=3):
    h = 10**(-precision)
    return (f(x+h) - f(x)) / h

def encrypt(f, a, m):
    y0 = f(a)
    y1 = f(m)
    s0 = s(f, a)
    s1 = s(f, m)
    if s0 == s1: return "NULL"
    x = (y1-y0 + s0*a - s1*m)/(s0-s1)
    return (x, s1*(x-m) + y1)

a = -9/4 * math.pi

l = input("What is the message? ")
for c in map(ord, l):
    print(encrypt(secret_func, a, c))
