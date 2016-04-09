#!/usr/bin/env python3

__author__ = 'Yatharth Agarwal <yatharth999@gmail.com>'


f = open('haystack.csv', 'w')

flag_line_number = 76
total_lines = 100

fields_per_line = 51  # would take a day with 4 cores for one line
flag_field = 42
name_field = 23

flag = 'zalgo_is_tony_the_pony_he_comes'
name = 'sHELLOu'

fields = list(map(str, range(fields_per_line)))
dummy_line = ','.join(fields)
fields[name_field] = name
fields[flag_field] = flag
flag_line = ','.join(fields)

for i in range(total_lines):
    f.write(flag_line if i == flag_line_number else dummy_line)
    f.write('\n')

f.close()