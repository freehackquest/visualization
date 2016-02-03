# Build
	$ qmake
	$ make

# Run params

	--framerate <number> (default 5)
	--time <number> (default -1 - infinity loop)
	--width <number> (default 1280)
	--height <number> (default 720)
	--disablelog - disabled logging

# Run example use ffplay

	$ cat examples/exampleScoreboard.visualization | \
	./visualization -framerate 5 -width 1280 -height | \
	ffplay -f rawvideo -pixel_format rgb24 -video_size 1280x720 -framerate 5 -i pipe:0

# Run example use avconv

	$ cat examples/exampleScoreboard.visualization | \
	./visualization -framerate 5 -width 1280 -height | \
	avconv -f rawvideo -pixel_format rgb24 -video_size 1280x720 -framerate 5 -i pipe:0

# How to RTMP server up

https://obsproject.com/forum/resources/how-to-set-up-your-own-private-rtmp-server-using-nginx.50/

# Run example to RTMP server

	$ cat examples/exampleScoreboard.visualization | \
	./visualization -framerate 5 -width 1280 -height | \
	ffmpeg -f rawvideo -pixel_format rgb24 -video_size 1280x720 -framerate 5 -i pipe:0 -f flv rtmp://host:port/live/exampleScoreboard
	
Use this link for looking streaming: rtmp://host:port/live/exampleScoreboard


# Commands

## Comment

Use character ```#``` for your comments

## Skip frames

	```skip <count> ``

## Draw object

	```draw <object> [<params>]```

## Colors

In the system used rgb spec:
* FFFFFF == RGB

### Predefined colors
	
* white == FFF
* black
* red
* green

## Predefined objects

### background
Usage: ```draw background <color>```
Examples:
* draw background 000000
* draw background FFFFFF
* draw background red

### line

Usage: ```draw line <number-x1> <number-y1> <number-x2> <number-y2> <number-width> <color>```

### rect

Usage: ```draw rect <number-x1> <number-y1> <number-x2> <number-y2> <color>```

### border

Usage: ```draw rect-border <number-x1> <number-y1> <number-x2> <number-y2> <number-width> <color>```

### pixel

Usage: ```draw pixel <number-x1> <number-y1> <color>```

## object table

	table <table-name>
	place name score
	1 team1 1000.22
	2 team2 900.21
	3 team3 100.00
	table end

Usage: ```draw <table-name> <number-x1> <number-y1> <color>```

## object frame

	frame <frame-name>
	# some commands
	frame end

Usage: ```<frame-name> <number-x1> <number-y1> <color>```

Example:

	frame frm1
	draw line 100 100 200 200 1 white
	draw pixel 100 200 red
	remove frm1
	frame end
	draw frm1

or

	frame frm1
	draw line 100 100 200 200 1 white
	draw pixel 100 200 red
	#remove frm1
	frame end
	draw frm1

## remove object which defined priviously

Usage: ```remove <object-name>```
