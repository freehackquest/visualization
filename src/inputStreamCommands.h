#ifndef INPUTSTREAMCOMMANDS_H
#define INPUTSTREAMCOMMANDS_H
#include <QTextStream>
#include <QFile>
#include "parser.h"
#include "icommand.h"
#include "logger.h"
#include <QWidget>
#include <QMutex>
#include <QtNetwork>
#include <QTcpServer>
#include <QTcpSocket>


class InputStreamCommands : public QObject{
		Q_OBJECT
	public:
		explicit InputStreamCommands(QObject *parent = 0);
		void setLogger(Logger *pLogger);
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
		Logger *m_pLogger;
		void pushCode(QString strCode);

	private slots:
		void slotNewConnection();
		void slotReadClient();
};

#endif // INPUTSTREAMCOMMANDS_H
