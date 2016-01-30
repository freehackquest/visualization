#ifndef DRAWOBJECTSCOLLECTION_H
#define DRAWOBJECTSCOLLECTION_H

#include "idrawobject.h"
#include <QString>
#include <QMap>

class DrawObjectsCollection {
		QMap<QString, IDrawObject*> m_mDrawObjects;
		void registr(IDrawObject* pDrawObject);
	public:
		DrawObjectsCollection();
		bool draw(QString name, Frame *pFrame, int nX, int nY);
};

#endif // DRAWOBJECTSCOLLECTION_H
