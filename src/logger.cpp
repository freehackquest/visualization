#include "logger.h"
#include <iostream>
#include <QDateTime>

Logger::Logger(){
	m_bEnabled = false;
	m_pTextStream = NULL;
	m_pLogger = NULL;
	m_pLogFile = NULL;
}

Logger::Logger(QString logfilename){
	m_bEnabled = false;
	m_pTextStream = NULL;
	m_pLogger = NULL;
	m_pLogFile = new QFile(logfilename);
	if (m_pLogFile->open(QIODevice::ReadWrite | QIODevice::Append | QIODevice::Text)) {
		m_pTextStream = new QTextStream(m_pLogFile);
		m_bEnabled = true;
	}else{
		std::cerr << "Cannot open file for writing: "
			<< m_pLogFile->errorString().toStdString() << std::endl;
	}
};

Logger::Logger(Logger *pLogger){
	m_bEnabled = false;
	m_pTextStream = NULL;
	m_pLogFile = NULL;
	m_pLogger = pLogger;
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

void Logger::warn(QString msg){
	message("WARN", msg);
}

void Logger::message(QString prefix, QString msg){
	QMutexLocker lock(&m_Mutex);
	if(m_pLogger != NULL){
		m_pLogger->message(prefix, msg);
	}else if(m_pTextStream != NULL && m_bEnabled){
		*m_pTextStream << "[" << QDateTime::currentDateTime().toString("yyyy-MM-dd hh:mm:ss") << "] " << prefix << " " << msg << "\n";
		m_pTextStream->flush(); // TODO
	}
};

void Logger::disable(){
	if(m_pLogger != NULL){
		m_pLogger->disable();
	}else{
		info("Logger disabled");
		m_bEnabled = false;	
	}
};

void Logger::enable(){
	if(m_pLogger != NULL){
		m_pLogger->enable();
	}else{
		info("Logger enabled");
		m_bEnabled = true;
	}
};
