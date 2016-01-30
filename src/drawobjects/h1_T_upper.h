#ifndef DRAWOBJECT_H1_T_UPPER_H
#define DRAWOBJECT_H1_T_UPPER_H

#include "../idrawobject.h"

class DrawObject_h1_T_upper : public IDrawObject {
	public:
		virtual QString name();
		virtual void draw(Frame *pFrame, int nX, int nY);
};

#endif // DRAWOBJECT_H1_T_UPPER_H
