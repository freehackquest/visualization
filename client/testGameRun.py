#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys, traceback, math, socket, re, random, os
from time import sleep
from FHQVisualizationLib import FHQVisualizationLib

host="localhost"
port=31001

with FHQVisualizationLib(host, port) as fhq:
	fhq.background("ffffff")
	fhq.pixel(1,1,"ffffff")
	fhq.line(1,1,2,2,1,"ffffff")

#host="localhost"

# while True:
	'''s.send("background 303030\n")
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
	sleep(3)'''

