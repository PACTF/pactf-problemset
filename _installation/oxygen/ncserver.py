#!/usr/bin/python3

import socketserver as ss
import threading as th
import subprocess as sp
import sys

class nc_handler(ss.StreamRequestHandler):
    def handle(self):
        self.process = sp.Popen(
            self.server.cmd,
            stdin=self.rfile,
            stdout=self.wfile
        )
        self.request.close()


class ThreadingTCPServer(ss.ThreadingMixIn, ss.TCPServer):
    def __init__(self, server_address, RequestHandlerClass, cmd):
        ss.TCPServer.__init__(self, server_address, RequestHandlerClass)
        self.cmd = cmd

    def verify_request(self, request, client_address):
        print(str(self.cmd) + " - " + str(client_address) + "\n")
        return True

if __name__ == '__main__':
    if len(sys.argv) < 2:
        print("Usage: python3 ncserver cmd [args ...]")
        exit(1)

    with open('ip') as infile:
        HOST = infile.read().strip()
    with open('port') as infile:
        PORT =  int(infile.read().strip())

    ss.TCPServer.allow_reuse_address = True
    ThreadingTCPServer.allow_reuse_address = True
    server = ThreadingTCPServer((HOST, PORT), nc_handler, sys.argv[1:])
    ip, port = server.server_address
    server.serve_forever()
