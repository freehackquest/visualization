#!/usr/bin/env python
# -*- coding: utf-8 -*-
from FHQVisualizationLib import FHQVisualizationLib
from time import sleep

host="localhost"
port=31001

with FHQVisualizationLib(host, port) as fhq:
	while True:
		fhq.showthreelock("keva")
		sleep(3)
		fhq.showthreelock("mustang")
		sleep(3)

