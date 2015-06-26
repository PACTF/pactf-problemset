#!/usr/bin/python

from itertools import cycle
from random import shuffle

acceptable = 'abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ\n'
key = cycle('topkek')

with open('fortune_data.txt') as f: data = f.read()

out = []
for char in data:
	if char not in acceptable: continue
	if char == '\n':
		if out[-1] != '\n': out.append(char)
		continue
	char = char.lower()
	out.append(char)
out = ''.join(out)
data = [l for l in out.split('\n') if 'flag' not in l]
data.append('theflagismonkeyseemonkeydo')
data.append('youshouldtryimportingjavaself')
shuffle(data)
data = '\n'.join(data)

with open('messages_unciphered.txt', 'w') as f:
	f.write(data)

out = []
for char in data:
	if char != '\n':
		char = ord(char) - ord('a')
		char += ord(next(key)) - ord('a')
		char %= 26
		char += ord('a')
		char = chr(char)
	out.append(char)

with open('message.txt', 'w') as f:
	f.write(''.join(out))
