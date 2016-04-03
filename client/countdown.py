#!/usr/bin/env python
# -*- coding: utf-8 -*-
from FHQVisualizationLib import FHQVisualizationLib
from time import sleep

host="localhost"
port=31001

with FHQVisualizationLib(host, port) as fhq:
	i = 1
	while True:
		fhq.countdown(5, "Round #" + str(i))
		sleep(7)
		i = i + 1
