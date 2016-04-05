#include "parseArgs.h"
#include <iostream>
#include <QString>

QStringList HelpersParseArgs::parse(QString str){
	int len = str.length();
	QStringList list;
	QString param = "";
	int nState = 0;
	for(int i = 0; i < len; i++){
		QChar next_c = i < len-1 ? str.at(i+1) : 0;
		QChar c = str.at(i);
		if(nState == 0 && c == QChar(' ')){
			if(param != ""){
				list << param;
				param = "";
			}
		}else if(nState == 1 && c == '\\' && next_c == '"'){
			param += '"';
			i++;
		}else if(nState == 2 && c == '\\' && next_c == '\''){
			param += '\'';
			i++;
		}else if((nState == 1 || nState == 2) && c == '\\' && next_c == '\\'){
			param += '\\';
			i++;
		}else if(nState == 0 && c == '"'){
			nState = 1;
		}else if(nState == 1 && c == '"'){
			nState = 0;
			list << param;
			param = "";
		}else if(nState == 0 && c == '\''){
			nState = 2;
		}else if(nState == 2 && c == '\''){
			nState = 0;
			list << param;
			param = "";
		}else{
			param += str.at(i);
		}
	}
	if(param != ""){
		list << param;
		param = "";
	}
	// TODO
	return list;
};

