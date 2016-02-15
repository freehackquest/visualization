#include "helpersParseArgs.h"
#include <iostream>
#include <QString>

QStringList HelpersParseArgs::parse(QString str){
	return str.split(" ");
};

