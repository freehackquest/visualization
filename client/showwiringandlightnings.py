#!/usr/bin/env python
# -*- coding: utf-8 -*-
from FHQVisualizationLib import FHQVisualizationLib
from time import sleep

host="localhost"
port=31001

with FHQVisualizationLib(host, port) as fhq:
	while True:
		fhq.showwiringandlightnings("keva", "ofoody")
		sleep(5)
		fhq.showwiringandlightnings("mustang", "ofoody")
		sleep(5)

