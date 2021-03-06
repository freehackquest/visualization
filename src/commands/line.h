#ifndef COMMAND_LINE_H
#define COMMAND_LINE_H
#include "../interfaces/icommand.h"
#include "../interfaces/icore.h"
#include <QString>
#include <QStringList>

class CommandLine : public ICommand {
	public:
		CommandLine();
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
		int distance(int x1, int x2);
		QString m_strName;
		QStringList m_listParams;
		int m_nX1;
		int m_nY1;
		int m_nX2;
		int m_nY2;
		int m_nWidth;
		int m_nColor;
		bool m_bCheck;
		QString m_sCheck;
};

#endif // COMMAND_LINE_H
