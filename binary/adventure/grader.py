#!/usr/bin/python

flags = ['pactf{i_lUv_D0tf1l3z}', 'pactf{H1d3_uR_s3kr1tz}', 'flag{w3w_l4d}']

def grade(team, flag):
    if flags[team % len(flags)] in flag:
        return True, "Don't you?"
    else:
        return False, "Try again!"
