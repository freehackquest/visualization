QT += gui core network widgets

TARGET = visualization
CONFIG += console release app_bundle
TEMPLATE = app
OBJECTS_DIR = tmp/
MOC_DIR = tmp/

RESOURCES = \
	visualization.qrc

SOURCES += \
	src/main.cpp \
	src/logger.cpp \
	src/frame.cpp \
	src/inputStreamCommands.cpp \
	src/renderStream.cpp \
	src/outputStream.cpp \
	src/parser.cpp \
	src/commandscollection.cpp \
	src/commands/background.cpp \
	src/commands/draw.cpp \
	src/commands/fix.cpp \
	src/commands/line.cpp \
	src/commands/pixel.cpp \
	src/commands/table.cpp \
	src/commands/text.cpp \
	src/helpersLine.cpp \
	src/helpersParseArgs.cpp \
	src/helpersText.cpp \

HEADERS += \
	src/idrawobject.h \
	src/icommand.h \
	src/logger.h \
	src/frame.h \
	src/inputStreamCommands.h \
	src/renderStream.h \
	src/outputStream.h \
	src/parser.h \
	src/commandscollection.h \
	src/commands/background.h \
	src/commands/draw.h \
	src/commands/fix.h \
	src/commands/line.h \
	src/commands/pixel.h \
	src/commands/table.h \
	src/commands/text.h \
	src/helpersLine.h \
	src/helpersParseArgs.h \
	src/helpersText.h \
	
