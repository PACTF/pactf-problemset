#!/usr/bin/env python3

__author__ = 'Yatharth Agarwal <yatharth999@gmail.com>'

import re


def check(flag):
    POWER = 5
    TEST_LIMIT = 3

    pat = re.compile(flag)

    upper = POWER ** (TEST_LIMIT - 1) + 3
    powers = [POWER ** i for i in range(TEST_LIMIT)]
    for times in range(1, upper):
        s = 'x' * times
        print(times, pat.fullmatch(s), times in powers)
        if bool(pat.fullmatch(s)) != (times in powers):
            return times

    for exponent in range(5):
        for delta in range(4):
            times = POWER ** exponent + delta
            s = 'x' * times
            print(times, exponent, delta, pat.fullmatch(s), bool(delta))
            if bool(pat.fullmatch(s)) == bool(delta):
                return times

    return -1


def grade(key, flag):
    try:
        fail = check(flag)
    except Exception as err:
        print(err)
        return False, "Please try a different regex."

    if fail < 0:
        return True, "Though don’t actually use this."
    else:
        # print(fail)
        return False, "You’re missing at least one case."
