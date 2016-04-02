#!/usr/bin/env python
# -*- coding: utf-8 -*-

from os import listdir
from os.path import isfile, join

mypath='src/commands'

onlyfiles = [f for f in listdir(mypath) if isfile(join(mypath, f))]
