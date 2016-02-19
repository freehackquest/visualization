#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys, traceback, math, socket, re, random, os
from time import sleep
from random import randint

#host="localhost"
host="localhost"
port=31001
s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
s.connect((host, port))
print s.recv(2048)
while True:
	s.send("background 303030\n")
	rows = random.randint(3,20)
	print rows
	i = 0
	s.send("table C8C8C8\n")
	s.send("№ Team Attack Defence Summary\n")
	while i < rows:
		row = str(i+1) + " "
		row = row + "team" + str(random.randint(1,rows)) + " "
		row = row + str(random.randint(0,1000000)) + " "
		row = row + str(random.randint(0,1000000)) + " "
		row = row + str(random.randint(0,1000000)) + " "
		row = row + "\n"
		s.send(row)
		i = i + 1
	s.send("table end\n")
	s.send("fix\n")
	sleep(3)

