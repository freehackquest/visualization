# Install Qt 5 on Ubuntu

	$ sudo apt-get install qtbase5-dev

# Build
	$ qmake
	$ make

### If qmake printed error

Printed like:

	$ qmake
	qmake: could not exec '/usr/lib/x86_64-linux-gnu/qt4/bin/qmake': No such file or directory

You need change to qt5 default

	$ sudo nano /usr/lib/x86_64-linux-gnu/qt-default/qtchooser/default.conf
	
And check

	$ qtchooser -print-env

# Run params

	--disablelog - disabled logging

# Default parameters

* framerate: 10
* width: 1280
* height: 720
* port: 31001

# Base colors:

* backgound: 0x303030
* text-color: 0xC8C8C8


# Run example use ffplay/avplay

	$ ./visualization | \
	ffplay -f rawvideo -pixel_format rgb32 -video_size 1280x720 -framerate 10 -i pipe:0

# Run example use ffmpeg/avconv

	$ ./visualization | \
	ffmpeg -f rawvideo -pixel_format rgb32 -video_size 1280x720 -framerate 10 -i pipe:0 -f mpeg4 output.avi

# How to RTMP server up

https://obsproject.com/forum/resources/how-to-set-up-your-own-private-rtmp-server-using-nginx.50/
https://www.vultr.com/docs/setup-nginx-rtmp-on-ubuntu-14-04

# Run example to RTMP server

	$ ./visualization | \
	ffmpeg -f rawvideo -pixel_format rgb32 -video_size 1280x720 -framerate 10 -i pipe:0 -f flv rtmp://host:port/live/visualization
	
Use this link for looking streaming: rtmp://host:port/live/visualization

# Connection to visualization server

	`nc localhost:31001`

# Manual by commands

[Manual by commands](COMMANDS.md)

## Comment

Usage: ```comment```

## createframe

Usage: ```createframe```

## pushframes

Usage: ```pushframes```

## Color

In the system used rgb spec:
* FFFFFF == RGB

## line

Usage: ```line <number-x1> <number-y1> <number-x2> <number-y2> <number-width> <color>```

## pixel

Usage: ```line <number-x1> <number-y1> <color>```

## background

Usage: ```background <color>```

## showthreelock

Usage: ```showthreelock <team_name>```

## showexploitrun

Usage: ```showexploitrun <team1> <team2> <ip1> <ip2> <flags> <success>```


### rect

Usage: ```rect <number-x1> <number-y1> <number-x2> <number-y2> <color>```

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
