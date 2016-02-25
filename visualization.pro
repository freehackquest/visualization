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
	src/core.cpp \
	src/inputStreamCommands.cpp \
	src/renderStream.cpp \
	src/outputStream.cpp \
	src/parser.cpp \
	src/commandscollection.cpp \
	src/commands/background.cpp \
	src/commands/createframe.cpp \
	src/commands/draw.cpp \
	src/commands/fhqvisualization.cpp \
	src/commands/line.cpp \
	src/commands/pixel.cpp \
	src/commands/pushframes.cpp \
	src/commands/table.cpp \
	src/commands/text.cpp \
	src/commands/tree.cpp \
	src/helpersParseArgs.cpp \

HEADERS += \
	src/interfaces/icommand.h \
	src/interfaces/icore.h \
	src/logger.h \
	src/core.h \
	src/inputStreamCommands.h \
	src/renderStream.h \
	src/outputStream.h \
	src/parser.h \
	src/commandscollection.h \
	src/commands/background.h \
	src/commands/createframe.h \
	src/commands/draw.h \
	src/commands/fhqvisualization.h \
	src/commands/line.h \
	src/commands/pixel.h \
	src/commands/pushframes.h \
	src/commands/table.h \
	src/commands/text.h \
	src/commands/tree.h \
	src/helpersParseArgs.h \
	
