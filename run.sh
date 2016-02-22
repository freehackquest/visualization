#!/bin/bash

## avconv -> ffmpeg

./visualization --framerate 2 | \
	avplay -f rawvideo -pixel_format rgb32 -video_size 1280x720 \
	-framerate 2 -i pipe:0
