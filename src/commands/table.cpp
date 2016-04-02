#include "table.h"
#include "../helpersParseArgs.h"
#include <iostream>
#include <QString>
#include <QVector>

CommandTable::CommandTable(){
};

bool CommandTable::isMultiLine(){
	return true;
};

ICommand *CommandTable::create(){
	return new CommandTable();
};

QString CommandTable::name(){
	return "table";
};

void CommandTable::setParams(QStringList list){
	m_listParams << list;
};

bool CommandTable::check(){
	return true;
};

bool CommandTable::check(QString &strResult){
	strResult = "OK";
	return true;
};

QString CommandTable::code(){
	return name() + " " + m_listParams.join(" ") + "\n\t" + m_listCode.join("\n\t") + "\n" + name() + " end";
}

void CommandTable::appendCode(QString line){
	m_listCode << line;
};
/*
void CommandTable::drawGrid(Frame *pFrame, int nX, int nY, QVector<int> &vColumnsWidth, int nRows, int nRowHeight, int nWidth, int nColor){
	int nRowWidth = 0;
	for(int i = 0; i < vColumnsWidth.size(); i++){
		nRowWidth += vColumnsWidth[i];
	}
	int nRowsHeight = nRows*nRowHeight;

	// simple center
	int nTmpX = nX;
	int nTmpY = nY;
	for(int i = 0; i < nRows; i++){
		HelpersLine::draw(pFrame, nTmpX, nTmpY, nTmpX + nRowWidth, nTmpY, nWidth, nColor);
		nTmpY += nRowHeight;
	}
	HelpersLine::draw(pFrame, nTmpX, nTmpY, nTmpX + nRowWidth, nTmpY, nWidth, nColor);

	nTmpX = nX;
	nTmpY = nY;
	for(int i = 0; i < vColumnsWidth.size(); i++){
		HelpersLine::draw(pFrame, nTmpX, nTmpY, nTmpX, nTmpY + nRowsHeight, nWidth, nColor);
		nTmpX += vColumnsWidth[i];
	}
	HelpersLine::draw(pFrame, nTmpX, nTmpY, nTmpX, nTmpY + nRowsHeight, nWidth, nColor);
};
*/

/*
 * @MANUAL START
 * @command table
 * @author Evgenii Sopov
 * @usage table
 * @example table <color>
 * @example	place name score
 * @example	1 team1 1000.22
 * @example	2 team2 900.21
 * @example	3 team3 100.00
 * @example table end
 * @description Multiline command, Not implemented yet
 * @MANUAL STOP
 * */
	
void CommandTable::run(ICore *pCore){
	/*int nWidth = pFrame->width();
	int nHeight = pFrame->height();
	int nColor = 0xC8C8C8;
	int nLineWidth = 1;
	int nFontSize = 20;
	int nPadding = 5;
	int nBorderPadding = 10;
	QString sFontName = "monospace";

	HelpersLine::draw(pFrame,        nBorderPadding,         nBorderPadding,        nBorderPadding, nHeight-nBorderPadding, nLineWidth, nColor);
	HelpersLine::draw(pFrame,        nBorderPadding, nHeight-nBorderPadding, nWidth-nBorderPadding, nHeight-nBorderPadding, nLineWidth, nColor);
	HelpersLine::draw(pFrame, nWidth-nBorderPadding, nHeight-nBorderPadding, nWidth-nBorderPadding,         nBorderPadding, nLineWidth, nColor);
	HelpersLine::draw(pFrame, nWidth-nBorderPadding,         nBorderPadding,        nBorderPadding,         nBorderPadding, nLineWidth, nColor);
	
	if(m_listCode.size() == 0)
		return;
	
	QStringList listHeaders = HelpersParseArgs::parse(m_listCode[0]);
	if(listHeaders.size() == 0)
		return;

	QVector<int> vColumnsWidth;
	for(int i = 0; i < listHeaders.size(); i++){
		listHeaders[i] = listHeaders[i].trimmed();
		vColumnsWidth.push_back(listHeaders[i].length());
	}
	
	for(int i = 0; i < m_listCode.size(); i++){
		QStringList listColumns = HelpersParseArgs::parse(m_listCode[i]);
		int cols = std::min(listColumns.size(), vColumnsWidth.size());
		for(int x = 0; x < cols; x++){
			vColumnsWidth[x] = std::max(listColumns[x].length(), vColumnsWidth[x]);
		}
	}
	
	int nRowWidth = 0;
	
	for(int i = 0; i < vColumnsWidth.size(); i++){
		vColumnsWidth[i] = vColumnsWidth[i]*(nFontSize + 2*nPadding);
		nRowWidth += vColumnsWidth[i];
	}

	int nRows = m_listCode.size()-1;
	int nRowHeight = nFontSize + 2*nPadding; // header
	int nRowsHeight = nRows*nRowHeight;

	if((nRowsHeight + nRowHeight) < nHeight){
		int nX = (nWidth - nRowWidth - 2*nBorderPadding)/2 + nBorderPadding;
		int nY = (nHeight - nRowHeight - nRowsHeight - 2*nBorderPadding)/2 + nBorderPadding;
		drawGrid(pFrame, nX, nY, vColumnsWidth, nRows, nRowHeight, nLineWidth, nColor);
		
		HelpersText::draw(
			pFrame,
			nX + nBorderPadding,
			nY + nBorderPadding/2,
			nColor,
			sFontName,
			nFontSize,
			QString("0123456789")
		);
	}else{
		
	}*/
}
