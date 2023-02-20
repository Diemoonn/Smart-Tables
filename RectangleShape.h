#pragma once

#include "AbstractItem.h"
#include <qpainter.h>

class RectangleShape : public AbstractItem
{
public:
	RectangleShape();
	RectangleShape(int x, int y, int width, int height, QMainWindow * surface, Qt::GlobalColor m_color, int thickness = 5);
	virtual void DrawItem();
	virtual void ResizeItem(float wK, float hK);

private:
	int m_thickness;
	Qt::GlobalColor m_color;
};

