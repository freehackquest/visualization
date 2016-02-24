#ifndef COMMAND_DRAW_H
#define COMMAND_DRAW_H
#include "../interfaces/icommand.h"
#include "../interfaces/icore.h"
#include <QString>
#include <QStringList>

class CommandDraw : public ICommand {
	public:
		CommandDraw();
		virtual bool isMultiLine();
		virtual ICommand *create();
		virtual QString name();
		virtual void setParams(QStringList list);
		virtual bool check();
		virtual bool check(QString &strResult);
		virtual QString code();
		virtual void appendCode(QString);
		virtual void run(ICore *pCore);
	private:
		QString m_strName;
		QStringList m_listParams;
};

#endif // COMMAND_DRAW_H
