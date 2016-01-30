#ifndef DRAWOBJECT_WHITEBORDERFRAME_H
#define DRAWOBJECT_WHITEBORDERFRAME_H

#include "../idrawobject.h"

class DrawObject_whiteBorderFrame : public IDrawObject {
	public:
		virtual QString name();
		virtual void draw(Frame *pFrame, int nX, int nY);
};

#endif // DRAWOBJECT_WHITEBORDERFRAME_H
