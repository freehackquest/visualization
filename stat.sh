#!/bin/bash

echo CPP:
find ./src -type f -name *.cpp -exec cat {} \; | wc -l
echo H:
find ./src -type f -name *.h -exec cat {} \; | wc -l
