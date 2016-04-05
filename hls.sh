#!/bin/bash

killall ffmpeg
killall ffplay
killall visualization

# -nostats -loglevel 0

./visualization | \
	ffmpeg -f rawvideo -pixel_format rgb32 -video_size 1280x720 \
	-framerate 10 -i pipe:0 -f hls \
	-hls_wrap 5 \
	-hls_segment_filename 'hls/file%03d.ts' \
	'hls/out.m3m8'


# ffplay -nostats -loglevel 0 rtmp://127.0.0.1:1935/live/testgame &
