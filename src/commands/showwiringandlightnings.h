#ifndef COMMAND_SHOWWIRINGANDLIGHTNIG_H
#define COMMAND_SHOWWIRINGANDLIGHTNIG_H
#include "../interfaces/icommand.h"
#include "../interfaces/icore.h"
#include <QString>
#include <QStringList>
 
class ShowWiringAndLightnings : public ICommand {
	public:
		ShowWiringAndLightnings();
		virtual ~ShowWiringAndLightnings();
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
		void printLighting(QImage *pFrame, int x1,int y1, int x2,int y2);
		void printWire(QImage *pFrame, int x1, int x2, int y);
		void copy(QImage *pBaseFrame, QImage *pFrame);
		QString m_strName;
		QStringList m_listParams;
		QString m_sTeam;
		QString m_sService;
		bool m_bCheck;
		QString m_sCheck;
};

#endif // COMMAND_SHOWWIRINGANDLIGHTNIG_H
