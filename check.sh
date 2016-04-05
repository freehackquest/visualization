#!/bin/bash

cd tests
qmake && make
./tests
