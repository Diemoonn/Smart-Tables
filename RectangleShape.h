#pragma once

#include <QtWidgets/QMainWindow>
#include <qpainter.h>

class RectangleShape
{
public:
	RectangleShape();
	RectangleShape(int width, int height, int x, int y, Qt::GlobalColor m_color, QMainWindow * surface, int thickness = 5);
	void DrawShape();

private:
	int m_x, m_y;
	int m_width, m_height, m_thickness;
	Qt::GlobalColor m_color;
	QMainWindow * m_surface;
};

