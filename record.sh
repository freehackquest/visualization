#!/bin/bash

if [ -f "output.avi" ]; then
	rm output.avi
fi

./visualization --framerate 5 | \
	ffmpeg -f rawvideo -pixel_format rgb32 -video_size 1280x720 \
	-framerate 5 -i pipe:0 -an -vcodec mpeg4 output.avi
