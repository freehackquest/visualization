#ifndef DRAWOBJECT_H1_F_UPPER_H
#define DRAWOBJECT_H1_F_UPPER_H

#include "../idrawobject.h"

class DrawObject_h1_F_upper : public IDrawObject {
	public:
		virtual QString name();
		virtual void draw(Frame *pFrame, int nX, int nY);
};

#endif // DRAWOBJECT_H1_F_UPPER_H
