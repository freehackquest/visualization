#include "text.h"
#include <iostream>
#include <QString>

CommandText::CommandText(){
};

bool CommandText::isMultiLine(){
	return false;
};

ICommand *CommandText::create(){
	return new CommandText();
};
	
QString CommandText::name(){
	return "text";
};

/*
 * @command line
 * @author Evgenii Sopov
 * @usage text <x1> <y1> <color> <text>
 * @param x1 - requared, integer
 * @param y1 - requared, integer
 * @param text - requared, string
 * */

void CommandText::setParams(QStringList list){
	m_listParams << list;
	m_sCheck = "";
	m_bCheck = true;
	QString sUsage = " Usage: 'text <x1> <y1> <color> <text>'"; 
	if(m_listParams.size() != 3){
		m_sCheck = "Expected 3 params. " + sUsage;
		m_bCheck = false;
		return;
	}
	bool bConvert = false;
	m_nX1 = m_listParams[0].toInt(&bConvert,10);
	if(!bConvert){
		m_sCheck = "Parameter x1 must be integer. " + sUsage;
		m_bCheck = false;
		return;
	}

	bConvert = false;
	m_nY1 = m_listParams[1].toInt(&bConvert,10);
	if(!bConvert){
		m_sCheck = "Parameter y1 must be integer. " + sUsage;
		m_bCheck = false;
		return;
	}

	bConvert = false;
	m_nColor = m_listParams[2].toInt(&bConvert,16);
	if(!bConvert){
		m_sCheck = "Parameter color must be integer. " + sUsage;
		m_bCheck = false;
		return;
	}

	QString m_sText = m_listParams[3];
};

bool CommandText::check(){
	return m_bCheck;
};

bool CommandText::check(QString &strCheck){
	strCheck = m_sCheck;
	return m_bCheck;
};

QString CommandText::code(){
	return name() + " " + m_listParams.join(" ");
}

void CommandText::appendCode(QString){
	// this command is single line
};

void CommandText::run(Frame *pFrame, DrawObjectsCollection *pDrawObjectsCollection){
	if(!m_bCheck) return;


	for(int i = 0; i < m_sText.length(); i++){
		
	};
/*
	int nDistanceX = distance(m_nX2,m_nX1);
	int nDistanceY = distance(m_nY2,m_nY1);
	double nDX = 1;
	double nDY = 1;
	int nLength = 0;

	if(nDistanceX > nDistanceY){
		nDY = double(nDistanceY)/double(nDistanceX);
		nLength = nDistanceX;
	}else{
		nDX = double(nDistanceX)/double(nDistanceY);
		nLength = nDistanceY;
	}

	nDX = m_nX2 > m_nX1 ? nDX : -1*nDX;
	nDY = m_nY2 > m_nY1 ? nDY : -1*nDY;
		
	double x = m_nX1;
	double y = m_nY1;
	for(int i = 0; i < nLength; i++){
		x=x+nDX;
		y=y+nDY;
		pFrame->setPixel(int(x),int(y),m_nColor);
	}
*/
};

