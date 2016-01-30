#ifndef DRAWOBJECT_BLACKFILLFRAME_H
#define DRAWOBJECT_BLACKFILLFRAME_H

#include "../idrawobject.h"

class DrawObject_blackFillFrame : public IDrawObject {
	public:
		virtual QString name();
		virtual void draw(Frame *pFrame, int nX, int nY);
};

#endif // DRAWOBJECT_BLACKFILLFRAME_H
