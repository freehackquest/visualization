#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys, traceback, math, socket, re, random, os
from time import sleep
from random import randint

host="localhost"
port=31001
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((host, port))
print s.recv(2048)
while True:
	w=randint(0,1280)
	h=randint(0,720)
	s.send("pixel " + str(w) + " " + str(h) + " ffffff\n")
	s.send("pixel " + str(w+1) + " " + str(h) + " ffffff\n")
	s.send("pixel " + str(w) + " " + str(h+1) + " ffffff\n")
	s.send("pixel " + str(w+1) + " " + str(h+1) + " ffffff\n")
	s.send("fix\n")
	sleep(0.2)

