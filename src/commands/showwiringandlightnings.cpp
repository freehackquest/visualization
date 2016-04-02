#include "showwiringandlightnings.h"
#include <iostream>
#include <QString>
#include <QFontMetrics>
#include <QFontDatabase>
#include <QPainter>
#include <cmath>
#include <QTime>
#include <QThread>
#include <QFile>

ShowWiringAndLightnings::ShowWiringAndLightnings(){
	m_sCheck = "";
	m_bCheck = true;
};

ShowWiringAndLightnings::~ShowWiringAndLightnings(){
};

bool ShowWiringAndLightnings::isMultiLine(){
	return false;
};

ICommand *ShowWiringAndLightnings::create(){
	return new ShowWiringAndLightnings();
};
	
QString ShowWiringAndLightnings::name(){
	return "showwiringandlightnings";
};

/*
 * @MANUAL START
 * @command showwiringandlightnings
 * @author Evgenii Sopov
 * @usage showexploterun <team> <searvice>
 * @example showwiringandlightnings keva ofoody
 * @param team - requared, string
 * @param searvice - requared, string
 * @youtube http://www.youtube.com/watch?v=JJCCrD3rd1s
 * @MANUAL STOP
 * */

void ShowWiringAndLightnings::setParams(QStringList list){
	m_listParams.clear();
	m_listParams << list;
	m_sCheck = "";
	m_bCheck = true;
	QString sUsage = " Usage: 'showwiringandlightnings <team> <service>'";
	if(m_listParams.size() != 2){
		m_sCheck = "Expected 2 params. " + sUsage;
		m_bCheck = false;
		return;
	}
	m_sTeam = m_listParams[0];
	m_sService = m_listParams[1];
};

bool ShowWiringAndLightnings::check(){
	return m_bCheck;
};

bool ShowWiringAndLightnings::check(QString &strCheck){
	strCheck = m_sCheck;
	return m_bCheck;
};

QString ShowWiringAndLightnings::code(){
	return name() + " " + m_listParams.join(" ");
}

void ShowWiringAndLightnings::appendCode(QString){
	// this command is single line
};

void ShowWiringAndLightnings::printWire(QImage *pFrame, int x1, int x2, int y){
	QPainter p(pFrame);
	QPen pen;
	pen.setWidth(10);
	pen.setColor(QColor(0xff9600));
	p.setPen(pen);

	int k = x1 < x2 ? 1 : -1;
	
	p.drawLine(x2 - k*25, y, x2 + k*200, y + 65);
	p.drawLine(x2 - k*25, y, x2 + k*200, y);
	p.drawLine(x2 - k*25, y, x2 + k*200, y - 65);
	
	pen.setWidth(30);
	pen.setColor(QColor(0xd47676));
	p.setPen(pen);
	p.drawLine(x2 - k*25, y, x2 + k*150 , y+50);
	pen.setColor(QColor(0x6286cf));
	p.setPen(pen);
	p.drawLine(x2 - k*25, y, x2 + k*150, y);
	pen.setColor(QColor(0x90cf62));
	p.setPen(pen);
	p.drawLine(x2 - k*25, y, x2 + k*150, y-50);
	
	// wire
	pen.setWidth(120);
	pen.setColor(QColor(0x00C8C8C8));
	p.setPen(pen);
	p.drawLine(x1, y, x2, y);
	p.end();
	
};
	
void ShowWiringAndLightnings::printLighting(QImage *pFrame, int x1,int y1, int x2,int y2){
	QPainter p(pFrame);
	QPen pen(QColor(0xb2fffe));
	pen.setWidth(2);
	p.setPen(pen);
	
	int number = 10;
	int randomValue = 5 + qrand() % number;
	
	int w = x2 - x1;
	int s = w/randomValue;
	if(s <= 2){
		return;
	}
	
	int start_x = x1;
	int start_y = y1;
	for(int i = 0; i < randomValue-1; i++){
		int new_x = start_x + s + (qrand()%s - s/2);
		int new_y = start_y + qrand() % 50 - 25;
		p.drawLine(start_x, start_y, new_x, new_y);
		start_x = new_x;
		start_y = new_y;
	}

	p.drawLine(start_x, start_y, x2, y2);
	p.end();
};

void ShowWiringAndLightnings::copy(QImage *pBaseFrame, QImage *pFrame){
	QPainter p(pFrame);
	p.drawImage(QPoint(0, 0), *pBaseFrame);
	p.end();
}

// special simbols: http://www.utf8-chartable.de/unicode-utf8-table.pl?start=9728

void ShowWiringAndLightnings::run(ICore *pCore){
	if(!m_bCheck) return;
	int nWidth = pCore->width();
	int nHeight = pCore->height();
	QImage *pBaseFrame = new QImage(QSize(nWidth,nHeight), QImage::Format_RGB32);
	pBaseFrame->fill(QColor(0x303030));

	int id = QFontDatabase::addApplicationFont(":/fonts/hack.regular.ttf");
	QString family = QFontDatabase::applicationFontFamilies(id).at(0);

	int nX = 0;
	int nY = 0;

	// create title
	{
		QFont font(family, 40);
		QFontMetrics fm(font);
		QString text = "☢ Service '" + m_sService + "' upped by " + m_sTeam;
		int nTextWidth = fm.width(text);
		int nTextHeight = fm.height();
		QPainter p(pBaseFrame);
		p.setPen(QPen(QColor(0x00C8C8C8)));
		p.setFont(font);
		nX = nWidth/2-nTextWidth/2;
		nY = 30 + nTextHeight;
		p.drawText(nX, nY, text);	
		p.end();
		nY += 30;
	}

	// paste logo
	QFile logoTeam(":/images/teams/" + m_sTeam + ".png");
	if(logoTeam.exists()){
		QImage imgLogo(":/images/teams/" + m_sTeam + ".png");
		QPainter p1(pBaseFrame);
		p1.drawImage(QPoint(nWidth - 20 - imgLogo.width(), nHeight - 20 - imgLogo.height()), imgLogo);
		p1.end();
	}else{
		pCore->logger()->debug("Logo for " + m_sTeam + " are not exists");
	}

	int x11 = 0;
	int x12 = nWidth/6;
	int x21 = nWidth;
	int x22 = nWidth - nWidth/6;
	int y = nHeight/2;

	int frames = pCore->framerate()*3;
	qsrand(QDateTime::currentMSecsSinceEpoch());
	int len = x21 - x12;
	int dx = len/(4*frames);
	for(int i = 0; i < frames; i++){
		QImage *pFrame = pCore->createFrame();
		copy(pBaseFrame, pFrame);
		
		printWire(pFrame, x11, x12, y);
		printWire(pFrame, x21, x22, y);

		printLighting(pFrame, x12 + 200, y+65, x22 - 200, y+65);
		printLighting(pFrame, x12 + 200, y, x22 - 200, y);
		printLighting(pFrame, x12 + 200, y-65, x22 - 200, y-65);
		printLighting(pFrame, x12 + 200, y+65, x22 - 200, y+65);
		printLighting(pFrame, x12 + 200, y, x22 - 200, y);
		printLighting(pFrame, x12 + 200, y-65, x22 - 200, y-65);
		x12 += dx;
		x22 -= dx;
	}

	pCore->pushFrames();
};

