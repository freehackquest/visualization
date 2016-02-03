# Build
	$ qmake
	$ make

# Run params

	-framerate <number> (default 5)
	-time <number> (default -1 - infinity loop)
	-width <number> (default 1280)
	-height <number> (default 720)

# Commands

## Comment
	\# - commentar

# Run example use ffplay

	$ cat exampleScoreboard.visualization | \
	./visualization -framerate 5 -width 1280 -height | \
	ffplay -f rawvideo -pixel_format rgb24 -video_size 1280x720 -framerate 5 -i pipe:0

# Run example use avconv

	$ cat exampleScoreboard.visualization | \
	./visualization -framerate 5 -width 1280 -height | \
	avconv -f rawvideo -pixel_format rgb24 -video_size 1280x720 -framerate 5 -i pipe:0

# How to RTMP server up

https://obsproject.com/forum/resources/how-to-set-up-your-own-private-rtmp-server-using-nginx.50/

# Run example to RTMP server

	$ cat exampleScoreboard.visualization | \
	./visualization -framerate 5 -width 1280 -height | \
	ffmpeg -f rawvideo -pixel_format rgb24 -video_size 1280x720 -framerate 5 -i pipe:0 -f flv rtmp://host:port/live/exampleScoreboard
	
Use this link for looking streaming: rtmp://host:port/live/exampleScoreboard


