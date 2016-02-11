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
color = str(randint(0,9)) + str(randint(0,9))
color = color + str(randint(0,9)) + str(randint(0,9)) 
color = color + str(randint(0,9)) + str(randint(0,9)) 
s.send("background " + color + "\n")

while True:
	x1=randint(0,1280)
	y1=randint(0,720)
	x2=randint(0,1280)
	y2=randint(0,720)

	s.send("line " + str(x1) + " " + str(y1) + " " + str(x2) + " " + str(y2) + " 1 ffffff\n"

	+ "pixel " + str(x2) + " " + str(y2) + " ffffff\n"
	+ "pixel " + str(x2+1) + " " + str(y2) + " ffffff\n"
	+ "pixel " + str(x2) + " " + str(y2+1) + " ffffff\n"
	+ "pixel " + str(x2+1) + " " + str(y2+1) + " ffffff\n"

	+ "pixel " + str(x1) + " " + str(y1) + " 000000\n"
	+ "pixel " + str(x1+1) + " " + str(y1) + " 000000\n"
	+ "pixel " + str(x1) + " " + str(y1+1) + " 000000\n"
	+ "pixel " + str(x1+1) + " " + str(y1+1) + " 000000\n"
	+ "fix\n")
	sleep(0.2)
	break

