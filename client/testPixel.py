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
s.send("background 000000\n")
i=0
while True:
	i=i+1
	x1=randint(0,1280)
	y1=randint(0,720)
	s.send("pixel " + str(x1) + " " + str(y1) + " ffffff\n")
	if i % 10 == 0:
		s.send("fix\n")
		sleep(0.2)

