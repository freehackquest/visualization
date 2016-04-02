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
	if len(st['example']) > 0:
		print("Example:\n\n\t" + "\n\t".join(st['example']) + "\n")
	if st['youtube'] != '':
		print("[Look on youtube](" + st['youtube'] + ")")
	print("*" + st['author'] + "*")

def getEmptyData():
	return {
		"command" : "",
		"author": "",
		"usage" : "",
		"example" : [],
		"youtube" : "",
		"params": [],
		"description": ""
	}

ptrn_manual_start = re.compile("[ \\t*]*@MANUAL[ \\t]+START[ \\t]*")
ptrn_manual_stop  = re.compile("[ \\t*]*@MANUAL[ \\t]+STOP[ \\t]*")
ptrn_command      = re.compile("[ \\t*]*@command[ \\t]+(.*)[ \\t]*")
ptrn_usage        = re.compile("[ \\t*]*@usage[ \\t]+(.*)[ \\t]*")
ptrn_author       = re.compile("[ \\t*]*@author[ \\t]+(.*)[ \\t]*")
ptrn_params       = re.compile("[ \\t*]*@param[ \\t]+(.*)[ \\t]*")
ptrn_description  = re.compile("[ \\t*]*@description[ \\t]+(.*)[ \\t]*")
ptrn_example  = re.compile("[ \\t*]*@example[ \\t]+(.*)[ \\t]*")
ptrn_youtube  = re.compile("[ \\t*]*@youtube[ \\t]+(.*)")

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
				data['example'].append(ptrn_example.match(line).group(1));
			elif manstarted is True and ptrn_params.match(line):
				data['params'].append(ptrn_params.match(line).group(1));
