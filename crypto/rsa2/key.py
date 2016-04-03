#!/usr/bin/python

from Crypto.PublicKey import RSA

with open('key.pem', 'r') as f:
    key = RSA.importKey(f.read())

with open('pub.pem', 'w') as f:
    f.write(key.publickey().exportKey().decode('ascii'))
