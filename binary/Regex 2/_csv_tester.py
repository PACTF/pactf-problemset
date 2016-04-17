#!/usr/bin/env python3

__author__ = 'Yatharth Agarwal <yatharth999@gmail.com>'

import re

pat_bad = re.compile(r'^(?:.*?,){29}(?:c\w+n),(?:.*?,){35}(.*?),.*$')
pat_good = re.compile(r'^(?:[^,]+,){29}(?:c\w+?n),(?:[^,]+,){35}(.*?),.*$')

good = 0
pat = pat_good if good else pat_bad


with open('/Users/Yatharth/Downloads/Temporary/haystack.csv') as f:

    for i, line in enumerate(f.readlines()):
        match = re.match(pat, line)
        if match is not None:
            print(i, match.groups())
            # break
        print(i, flush=True)