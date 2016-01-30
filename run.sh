#!/bin/bash

if [ -f "output.avi" ]; then
	rm "output.avi"
fi
## avconv -> ffmpeg

./visualization | avconv -f rawvideo -video_size 1280x720 \
	-pixel_format rgb24 -framerate 5 -i pipe:0 -t 15 -an \
	output.avi

avplay output.avi

#./visualization | avplay -f rawvideo -pixel_format rgb24 -video_size 1280x720 -framerate 5 -t 15 -i pipe:0
