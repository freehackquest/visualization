#!/bin/bash

if [ -f "output.mkv" ]; then
	rm "output.mkv"
fi

#./stream_generator | ffmpeg -f rawvideo -video_size 1280x720 \
#	-pixel_format rgb24 -framerate 25 -i pipe:0 -an \
#	output.mkv

./stream_generator | ffplay -f rawvideo -pixel_format rgb24 -video_size 1280x720 -framerate 25 -i pipe:0
