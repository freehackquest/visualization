#ifndef ICOMMAND_H
#define ICOMMAND_H
#include <QString>
#include <QStringList>
#include <QVector>
#include <QImage>
#include "icore.h"

class ICommand {
	public:
		virtual ~ICommand() {};
		virtual bool isMultiLine() = 0;
		virtual ICommand *create() = 0;
		virtual QString name() = 0;
		virtual void setParams(QStringList list) = 0;
		virtual bool check() = 0;
		virtual bool check(QString &strResult) = 0;
		virtual QString code() = 0;
		virtual void appendCode(QString) = 0;
		virtual void run(ICore *pCore) = 0;
};

#endif // ICOMMAND_H
