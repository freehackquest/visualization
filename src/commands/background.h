#ifndef COMMAND_BACKGROUND_H
#define COMMAND_BACKGROUND_H
#include "../interfaces/icommand.h"
#include "../interfaces/icore.h"
#include <QString>
#include <QStringList>

class CommandBackground : public ICommand {
	public:
		CommandBackground();
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
		bool m_bCheck;
		QString m_sCheck;
		int m_nColor;
		QStringList m_listParams;
};

#endif // COMMAND_BACKGROUND_H
