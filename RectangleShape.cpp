#include "RectangleShape.h"

RectangleShape::RectangleShape()
	: m_width(0), m_height(0), m_x(0), m_y(0), m_color(Qt::GlobalColor::black), m_surface(nullptr), m_thickness(0)
{
}

RectangleShape::RectangleShape(int width, int height, int x, int y, Qt::GlobalColor color, QMainWindow * surface, int thickness)
	: m_width(width), m_height(height), m_x(x), m_y(y), m_color(color), m_surface(surface), m_thickness(thickness)
{
}

void RectangleShape::DrawShape()
{
	QPainter painter(m_surface);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setBrush(QBrush(m_color));

	QPen pen;
	pen.setColor(m_color);
	pen.setWidth(m_thickness);

	painter.setPen(pen);
	painter.drawRect(m_x, m_y, m_width, m_height);
}


