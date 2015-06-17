#!/usr/bin/python

from itertools import cycle

key = cycle('topkek')

def uncipher(c):
	if c not in 'abcdefghijklmnopqrstuvwxyz': return c
	c = ord(c) - ord('a')
	c -= ord(next(key)) - ord('a')
	c %= 26
	return chr(c + ord('a'))

with open('message.txt') as f:
	for line in f:
		print(''.join(map(uncipher, line)))
