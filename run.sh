#!/bin/bash

if [ -f "output.avi" ]; then
	rm "output.avi"
fi
## avconv -> ffmpeg

#./visualization -framerate 5 -time 15 | avconv -f rawvideo -video_size 1280x720 \
	-pixel_format rgb24 -framerate 5 -i pipe:0 -an \
	-vcodec mpeg4 output.avi

#avplay output.avi

#./visualization -framerate 5 -time 5 | avplay -f rawvideo -pixel_format rgb24 -video_size 1280x720 -framerate 5 -t 15 -i pipe:0


#./visualization -framerate 5 -time 15 | ffmpeg -f rawvideo -video_size 1280x720 \
	-pixel_format rgb24 -framerate 5 -i pipe:0 -an \
	-vcodec mpeg4 output.avi

#ffplay output.avi

./visualization -framerate 5 -time 5 | ffplay -f rawvideo -pixel_format rgb24 -video_size 1280x720 -framerate 5 -i pipe:0
