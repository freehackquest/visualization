# Install Qt 5 on Ubuntu
	$ sudo apt-get install qtbase5-dev

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

Usage: ```skip <count>```

## Fix frame (send to output)

Usage: ```fix```

## Color

In the system used rgb spec:
* FFFFFF == RGB

### Predefined colors
	
* white == FFF
* black
* red
* green

## line

Usage: ```line <number-x1> <number-y1> <number-x2> <number-y2> <number-width> <color>```

## pixel

Usage: ```line <number-x1> <number-y1> <color>```

## Draw object

Usage: ```draw <object> [<params>]```

## Fill background

Usage: ```background <color>```

## Predefined objects

### background
Usage: ```background <color>```

Examples:
* background 000000
* background FFFFFF
* background red


### rect

Usage: ```draw rect <number-x1> <number-y1> <number-x2> <number-y2> <color>```

### border

Usage: ```draw rect-border <number-x1> <number-y1> <number-x2> <number-y2> <number-width> <color>```

### pixel

Usage: ```draw pixel <number-x1> <number-y1> <color>```

## Define new objects
### table

	table <table-name>
	# data
	table end

Usage: ```draw <table-name> <number-x1> <number-y1> <border-color> <fill-color>```

Example:
	
	table tbl1
	place name score
	1 team1 1000.22
	2 team2 900.21
	3 team3 100.00
	table end
	
	draw tbl1 100 200 white black

### frame

	frame <frame-name>
	# some commands
	frame end

Usage: ```<frame-name> <number-x1> <number-y1> <color>```

Example:

	frame frm1
	draw background black
	draw line 100 100 200 200 1 white
	draw pixel 100 200 red
	frame end
	
	frame frm2
	draw background black
	draw line 200 200 100 100 1 white
	draw pixel 100 200 red
	frame end
	
	draw frm1
	skip 5
	draw frm2
	skip 5
	draw frm1
	skip 5
	
	remove frm1
	remove frm2

### remove object which defined priviously

Usage: ```remove <object-name>```
