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

if __name__ == '__main__':
    HOST, PORT = 'localhost', 1234
    ss.TCPServer.allow_reuse_address = True
    ThreadingTCPServer.allow_reuse_address = True
    server = ThreadingTCPServer((HOST, PORT), nc_handler, sys.argv[1])
    ip, port = server.server_address
    server.serve_forever()
