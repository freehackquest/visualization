#ifndef INPUTSTREAMCOMMANDS_H
#define INPUTSTREAMCOMMANDS_H
#include <QTextStream>
#include <QFile>
#include "interfaces/icommand.h"
#include "interfaces/icore.h"
#include "parser.h"
#include "logger.h"
#include <QWidget>
#include <QMutex>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>

class InputStreamCommands : public QObject{
		Q_OBJECT
	public:
		InputStreamCommands(ICore *pCore, QObject *parent = 0);
		bool hasCommand();
		ICommand *command();
		void pushCommand(ICommand *pCommand);
		void start(int nPort = 31001);
		void stop();

	private:
		QTcpServer *m_pTcpServer;
		QTcpSocket* m_pTcpSocket;
		Parser *m_pParser;
		QVector<ICommand *> m_vCommands;
		QMutex m_MutexCommand;
		QMutex m_MutexCode;
		ILogger *m_pLogger;
		ICore *m_pCore;
		void pushCode(QString strCode);
		
	private slots:
		void slotNewConnection();
		void slotReadClient();
};

#endif // INPUTSTREAMCOMMANDS_H
