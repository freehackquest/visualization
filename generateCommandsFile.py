#!/usr/bin/env python
# -*- coding: utf-8 -*-

import os, re

commandspath='src/commands/'
commands = []

for file in os.listdir(commandspath):
	if file.endswith(".cpp"):
		commands.append(file)
commands.sort()

print("# Manual by Commands")

def printData(st):
	print("")
	print("##" + st['command'])
	print("Usage: `" + st['usage'] + "`")
	i = 0;
	for param in data['params']:
		if i == 0:
			print("")
		i = i + 1
		print(str(i) + ". " + param)
	print("")
	print(st['description'])
	if st['example'] != '':
		print("Example: `" + st['example'] + "`\n")
	if st['youtube'] != '':
		print("[Look on youtube](" + st['youtube'] + ")")
	print("*" + st['author'] + "*")

def getEmptyData():
	return {
		"command" : "",
		"author": "",
		"usage" : "",
		"example" : "",
		"youtube" : "",
		"params": [],
		"description": ""
	}

ptrn_manual_start = re.compile("[ *]*@MANUAL START[ \\t]*")
ptrn_manual_stop  = re.compile("[ *]*@MANUAL STOP[ \\t]*")
ptrn_command      = re.compile("[ *]*@command (.*)[ \\t]*")
ptrn_usage        = re.compile("[ *]*@usage (.*)[ \\t]*")
ptrn_author       = re.compile("[ *]*@author (.*)[ \\t]*")
ptrn_params       = re.compile("[ *]*@param (.*)[ \\t]*")
ptrn_description  = re.compile("[ *]*@description (.*)[ \\t]*")
ptrn_example  = re.compile("[ *]*@example (.*)[ \\t]*")
ptrn_youtube  = re.compile("[ *]*@youtube (.*)[ \\t]*")

for filename in commands:
	# search keywords
	manstarted = False
	data = getEmptyData();
	with open(commandspath + filename) as f:
		for line in f:
			if ptrn_manual_start.match(line):
				manstarted = True
				struct = getEmptyData()
			elif ptrn_manual_stop.match(line):
				manstarted = False
				printData(data)

			if manstarted is True and ptrn_command.match(line):
				data['command'] = ptrn_command.match(line).group(1);
			elif manstarted is True and ptrn_usage.match(line):
				data['usage'] = ptrn_usage.match(line).group(1);
			elif manstarted is True and ptrn_author.match(line):
				data['author'] = ptrn_author.match(line).group(1);
			elif manstarted is True and ptrn_youtube.match(line):
				data['youtube'] = ptrn_youtube.match(line).group(1);
			elif manstarted is True and ptrn_description.match(line):
				data['description'] = data['description'] + ptrn_description.match(line).group(1) + "\n";
			elif manstarted is True and ptrn_example.match(line):
				data['example'] = data['example'] + ptrn_example.match(line).group(1) + "\n";
			elif manstarted is True and ptrn_params.match(line):
				data['params'].append(ptrn_params.match(line).group(1));
