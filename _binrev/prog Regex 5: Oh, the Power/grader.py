#!/usr/bin/env python3

__author__ = 'Yatharth Agarwal <yatharth999@gmail.com>'

import re
import random



def grade(key, flag):
    power = 5

    limit = 3
    upper = power**(limit-1) + 1
    powers = [power**i for i in range(limit)]
    flag = flag

    print("Powers")
    print()
    for i, power in enumerate(powers):
        s = 'x' * power
        print(re.match(flag, s) is not None, '\t', i)
        if re.match(flag, s) is None:
            return False, "You're missing at least one case."
    print()
    print()

    print("Random")
    print()
    for i in range(20):
        times = random.randint(1, upper)
        s = 'x' * times
        if times in powers:
            print("Ski", '\t', i, times)
            continue
        print(re.match(flag, s) is None, '\t', i, times)
        if  re.match(flag, s) is not None:
            return False, "You're missing at least one case."

    print()
    print()

    print("All", flush=True)
    print()

    for i in range(1, upper):
        if i in powers:
            continue
        s = 'x' * i
        if re.match(flag, s) is not None:
            print(re.match(flag, s) is None, '\t', i, times, flush=True)
            if re.match(flag, s) is not None:
                return False, "You're missing at least one case."

    print()
    print()

    print("Done")
    return True, "You weild The Elegant Weapon for a More Civilized Age"
