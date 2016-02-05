QT += core
QT += gui
QT += widgets
QT += sql

TARGET = visualization
CONFIG += console release app_bundle
TEMPLATE = app
OBJECTS_DIR = tmp/
MOC_DIR = tmp/

SOURCES += \
	src/main.cpp \
	src/logger.cpp \
	src/frame.cpp \
	src/inputThread.cpp \
	src/parser.cpp \
	src/commandscollection.cpp \
	src/commands/draw.cpp \
	src/commands/skip.cpp \
	src/commands/background.cpp \
	src/commands/table.cpp \
	src/drawobjectscollection.cpp \
	src/drawobjects/blackFillFrame.cpp \
	src/drawobjects/h1_C_upper.cpp \
	src/drawobjects/h1_T_upper.cpp \
	src/drawobjects/h1_F_upper.cpp \
	src/drawobjects/h1_I_lower.cpp \
	src/drawobjects/h1_G_lower.cpp \
	src/drawobjects/h1_H_lower.cpp \
	src/drawobjects/h1_T_lower.cpp \
	src/drawobjects/whiteBorderFrame.cpp \

HEADERS += \
	src/idrawobject.h \
	src/icommand.h \
	src/logger.h \
	src/frame.h \
	src/inputThread.h \
	src/parser.h \
	src/commandscollection.h \
	src/commands/draw.h \
	src/commands/skip.h \
	src/commands/background.h \
	src/commands/table.h \
	src/drawobjectscollection.h \
	src/drawobjects/blackFillFrame.h \
	src/drawobjects/h1_C_upper.h \
	src/drawobjects/h1_T_upper.h \
	src/drawobjects/h1_F_upper.h \
	src/drawobjects/h1_I_lower.h \
	src/drawobjects/h1_G_lower.h \
	src/drawobjects/h1_H_lower.h \
	src/drawobjects/h1_T_lower.h \
	src/drawobjects/whiteBorderFrame.h \
	

