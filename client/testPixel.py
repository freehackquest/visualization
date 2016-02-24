#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys, traceback, math, socket, re, random, os
from time import sleep
from random import randint
from FHQVisualizationLib import FHQVisualizationLib

host="localhost"
port=31001

with FHQVisualizationLib(host, port) as fhq:
	fhq.background("000000")
	i=0
	while True:
		i=i+1
		x=randint(0,1280)
		y=randint(0,720)
		fhq.pixel(x,y,"ffffff")
		if i % 10 == 0:
			fhq.fix()
			sleep(0.2)

