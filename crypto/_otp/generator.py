#!/usr/bin/python

import random, string, itertools

m1 = "I wonder what the flag could be? It's not like you can crack this cipher!"
m2 = "The flag, that you can't crack, is this: cR1b_dr4G_b01z_{%s}"

desc = '''This encryption is unbreakable! Good luck getting this one!

    {}

    {}'''

def randword(length):
    return ''.join(random.choice(string.ascii_lowercase) for i in range(length))

def hex_str(s):
    return ''.join(hex(c)[2:].zfill(2) for c in s)

def generate(key):
    random.seed(key)
    m2_ = m2 % randword(len(m1)-len(m2)+2)
    key = itertools.cycle(randword(len(m1) // 2))
    m1_c = hex_str(ord(c1) ^ ord(c2) for c1, c2 in zip(m1, key))
    m2_c = hex_str(ord(c1) ^ ord(c2) for c1, c2 in zip(m2_, key))
    return (
        desc.format(m1_c, m2_c),
        "Don't drag your feet, welcome to my crib! "
        "Don't throw out your keys, just use them over and over again!"
    )
