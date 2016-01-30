#ifndef DRAWOBJECT_H1_T_LOWER_H
#define DRAWOBJECT_H1_T_LOWER_H

#include "../idrawobject.h"

class DrawObject_h1_T_lower : public IDrawObject {
	public:
		virtual QString name();
		virtual void draw(Frame *pFrame, int nX, int nY);
};

#endif // DRAWOBJECT_H1_T_LOWER_H
