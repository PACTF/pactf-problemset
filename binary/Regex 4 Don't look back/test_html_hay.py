#!/usr/bin/env python3

__author__ = 'Yatharth Agarwal <yatharth999@gmail.com>'

import re

f = open('small_haystack.html')
s = f.read()

# sb = ','.join(map(str, range(30)))
# sg = """1,2,3,4,5,6,7,8,9,10,11,12,P13,14"""

# pb = r'(?:.*?,){12}P'
# pg = r'(?:[^,]+,){12}P'
pb = r'<html>.*?<head>.*?</head>.*?<body>.*?</body>.*?</html>'
#pg = r'<html>(?=(?P<tmp>))(?P=tmp)<head>.*?</head>.*?<body[^>]*>.*?</body>.*?</html>'
pg = r'<html>(?:(?!<head>).)*<head></head><body[^>]*>.*?</body>.*?</html>'
# pg = r'(?=(?P<tmp>' + '))(?P=tmp)' #

print(re.match(pg, s), flush=True)
print(re.match(pb, s))