#include "logger.h"
#include <iostream>
#include <QDateTime>

Logger::Logger(QString logfilename){
	m_bEnabled = false;
	m_pTextStream = NULL;
	QFile logfile(logfilename);
	if (logfile.open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text)) {
		m_pTextStream = new QTextStream(&logfile);
		m_bEnabled = true;
	}else{
		std::cerr << "Cannot open file for writing: "
			<< logfile.errorString().toStdString() << std::endl;
	}
};

void Logger::info(QString msg){
	message("INFO", msg);
};

void Logger::debug(QString msg){
	message("DEBUG", msg);
};

void Logger::error(QString msg){
	message("DEBUG", msg);
};

void Logger::message(QString prefix, QString msg){
	QMutexLocker lock(&m_Mutex);
	if(m_pTextStream != NULL && m_bEnabled){
		*m_pTextStream << "[" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << "] " << prefix << " " << msg << "\n";
		m_pTextStream->flush(); // TODO
	}
};

void Logger::disable(){
	info("Logger disabled");
	m_bEnabled = false;
}

void Logger::enable(){
	info("Logger enabled");
	m_bEnabled = true;
};
