#!/usr/bin/env python
# -*- coding: utf-8 -*-
import sys, traceback, math, socket, re, random, os
from time import sleep
from random import randint

class FHQVisualizationLib:
	def __init__(self, host, port):
		self.s = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
		self.s.connect((host, port))
		print self.s.recv(2048)
	def __enter__(self):
		return self
	def __exit__(self, exc_type, exc_value, traceback):
		self.s.close()
		print "Diconnect"
	def send(self,args):
		self.s.send(" ".join(args) + "\n")
	def background(self, color):
		self.send(["background",color])
	def fhqvisualization(self):
		self.send(["fhqvisualization"])	
	def pixel(self, x, y, color):
		self.send(["pixel",str(x),str(y),color])
	def line(self, x1, y1, x2, y2, w, color):
		self.send(["line",str(x1),str(y1),str(x1),str(y1),str(w),color])
	def createframe(self):
		self.send(["createframe"])
	def pushframes(self):
		self.send(["pushframes"])
	def tree(self):
		self.send(["tree"])
	def showexploitrun(self,team1,team2,ip1,ip2,flags,success):
		self.send(["showexploitrun", team1,team2,ip1,ip2,str(flags),str(success)])
	def showthreelock(self,team):
		self.send(["showthreelock", team])
 
