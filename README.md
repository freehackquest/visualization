# Build
	$ qmake
	$ make

# Run params

	-framerate <number> (default 5)
	-time <number> (default -1 - infinity loop)
	-width <number> (default 1280)
	-height <number> (default 720)

# stdin commands



# Example Run

```cat example.game | ./visualization -framerate 5 | \
	ffplay -f rawvideo -pixel_format rgb24 \
	-video_size 1280x720 -framerate 5 -i pipe:0```

# Live streaming RTMP server

https://obsproject.com/forum/resources/how-to-set-up-your-own-private-rtmp-server-using-nginx.50/
