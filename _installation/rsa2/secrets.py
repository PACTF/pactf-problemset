#!/usr/bin/python

flag = 'flag{0opZ_i_g00fd}'

if __name__ == '__main__':
    from Crypto.PublicKey import RSA
    with open('key.pem', 'r') as f:
        key = RSA.importKey(f.read())
    enc = key.encrypt(bytes(flag, 'ascii'), 0)
    with open('static/message.txt', 'w') as f:
        f.write(''.join(hex(c)[2:] for c in enc[0]))
