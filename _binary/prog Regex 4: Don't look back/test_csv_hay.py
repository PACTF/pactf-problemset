#!/usr/bin/env python3

__author__ = 'Yatharth Agarwal <yatharth999@gmail.com>'

import re

f = open('haystack.csv')

pat_bad = re.compile(r'^(?:.*?,){23}s\w+u,(?:.*?,){18}(.*?),.*$')
pat_good = re.compile(r'^(?:[^,]+,){23}s\w+?u,(?:[^,]+,){18}(.*?),.*$')

pat = pat_good

for i, line in enumerate(f.readlines()):
    match = re.match(pat, line)
    if match is not None:
        print(i, match.groups())
    else:
        print(i, 'fail')

f.close()