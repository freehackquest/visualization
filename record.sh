#!/bin/bash

if [ -f "output.avi" ]; then
	rm output.avi
fi

./visualization | \
	avconv -f rawvideo -pixel_format rgb32 -video_size 1280x720 \
	-framerate 10 -i pipe:0 -an -c:v libx264 output.avi
