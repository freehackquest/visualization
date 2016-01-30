
#include "drawobjectscollection.h"
#include "drawobjects/h1_C_upper.h"
#include "drawobjects/h1_T_upper.h"
#include "drawobjects/h1_F_upper.h"
#include "drawobjects/h1_I_lower.h"
#include "drawobjects/h1_G_lower.h"
#include "drawobjects/h1_H_lower.h"
#include "drawobjects/h1_T_lower.h"
#include "drawobjects/blackFillFrame.h"
#include "drawobjects/whiteBorderFrame.h"
#include <iostream>

DrawObjectsCollection::DrawObjectsCollection(){
	 registr(new DrawObject_blackFillFrame());
	 registr(new DrawObject_h1_C_upper());
	 registr(new DrawObject_h1_T_upper());
	 registr(new DrawObject_h1_F_upper());
	 registr(new DrawObject_h1_I_lower());
	 registr(new DrawObject_h1_G_lower());
	 registr(new DrawObject_h1_H_lower());
	 registr(new DrawObject_h1_T_lower());
	registr(new DrawObject_whiteBorderFrame());	 
};

void DrawObjectsCollection::registr(IDrawObject* pDrawObject){
	m_mDrawObjects[pDrawObject->name()] = pDrawObject;
}

bool DrawObjectsCollection::draw(QString name, Frame *pFrame, int nX, int nY){
	if(!m_mDrawObjects.contains(name))
		return false;
	m_mDrawObjects[name]->draw(pFrame, nX, nY);
	return true;
}

