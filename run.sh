#!/bin/bash

## avconv -> ffmpeg

./visualization | \
	ffplay -f rawvideo -pixel_format rgb32 -video_size 1280x720 \
        -framerate 10 -i pipe:0
