#!/bin/bash

killall ffmpeg
killall ffplay
killall visualization

./visualization --framerate 5 | \
	ffmpeg -nostats -loglevel 0 -f rawvideo -pixel_format rgb32 -video_size 1280x720 \
	-framerate 5 -i pipe:0 -f flv rtmp://127.0.0.1:1935/live/testgame &

ffplay -nostats -loglevel 0 rtmp://127.0.0.1:1935/live/testgame &
