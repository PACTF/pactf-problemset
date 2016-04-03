#!/usr/bin/python

import socketserver as ss
import threading as th
from Crypto.PublicKey import RSA

from secrets import flag

with open('key.pem', 'r') as f:
    key = RSA.importKey(f.read())

WELCOME_MSG = '''Welcome to the PA secret decryption service!

Please enter the data you wish to have decrypted.
'''

class rsa2_handler(ss.BaseRequestHandler):
    def handle(self):
        self.request.sendall(bytes(WELCOME_MSG, 'ascii'))
        self.data = self.request.recv(1024).strip()
        self.request.sendall(bytes(
            'Decrypting data from {}... '.format(self.client_address[0]),
            'ascii'
        ))
        encrypted = []
        for i in range(0, len(self.data), 2):
            encrypted.append(int(self.data[i:i+2].decode('ascii'), 16))
        msg = key.decrypt(bytes(encrypted))
        if msg.decode('ascii') == flag:
            self.request.sendall(b"Hey! That's our flag! You can't have that!")
        else:
            self.request.sendall(bytes(
                "Your decrypted data is:\n\n{}\n\n".format(
                    ''.join(hex(c)[2:] for c in msg)
                ), 'ascii'
            ))
        self.request.sendall("Remember to decode your hex data!")
        self.request.close()

class ForkingTCPServer(ss.ForkingMixIn, ss.TCPServer):
    pass

if __name__ == '__main__':
    HOST, PORT = 'localhost', 1234
    ForkingTCPServer.allow_reuse_address = True
    server = ForkingTCPServer((HOST, PORT), rsa2_handler)
    ip, port = server.server_address
    server.serve_forever()
