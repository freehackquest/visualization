#ifndef IDRAWOBJECT_H
#define IDRAWOBJECT_H

#include <QString>
#include "frame.h"

class IDrawObject {
	public:
		virtual QString name() = 0;
		virtual void draw(Frame *pFrame, int nX, int nY) = 0;
};

#endif // IDRAWOBJECT_H
