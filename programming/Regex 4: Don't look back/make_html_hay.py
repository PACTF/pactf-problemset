#!/usr/bin/env python3

__author__ = 'Yatharth Agarwal <yatharth999@gmail.com>'

filesize = 16

f = open('haystack.html', 'w')
f.write('<html><head></head><body>')

chunk_size = 12
loop_size = 3

chunk = '_'*10**5
filesize -= chunk_size + loop_size

print("left", 10**filesize)
for i in range(10**filesize):
    print("done", i, flush=True)
    for j in range(10**loop_size):
        f.write(chunk)

f.write('</body>')
f.close()
print("closed")