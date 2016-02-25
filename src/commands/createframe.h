#ifndef COMMAND_CREATEFRAME_H
#define COMMAND_CREATEFRAME_H
#include "../interfaces/icommand.h"
#include "../interfaces/icore.h"
#include <QString>
#include <QStringList>

class CommandCreateFrame : public ICommand {
	public:
		CommandCreateFrame();
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
		int m_nX1;
		int m_nY1;
		int m_nColor;
		QString m_sText;
		bool m_bCheck;
		QString m_sCheck;
};

#endif // COMMAND_CREATEFRAME_H
