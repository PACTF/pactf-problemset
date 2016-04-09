#!/usr/bin/python

import random

m1 = "I wonder what the flag could be? It's not like you can crack this cipher!"
m2 = "The flag, that you can't crack, is this: cR1b_dr4G_b01z_{%s}"

def grade(key, flag):
    random.seed(key)
    m2_ = m2 % randword(len(m1)-len(m2)+2)
    if m2_[41:] in flag:
        return True, "Isn't crib dragging fun?"
    else:
        return False, "Bzzt!"
