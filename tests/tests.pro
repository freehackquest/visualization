QT += gui core network widgets testlib

TARGET = tests
CONFIG += console release app_bundle
CONFIG += testcase
TEMPLATE = app
OBJECTS_DIR = tmp/
MOC_DIR = tmp/

SOURCES += \
	src/main.cpp \
	../src/helpers/parseArgs.cpp \
	src/testParseArgs.cpp \

HEADERS += \
	../src/helpers/parseArgs.h \
	src/testParseArgs.h \
	
