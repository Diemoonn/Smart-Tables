#include "RectangleShape.h"

RectangleShape::RectangleShape()
	: AbstractItem(0, 0, 0, 0, nullptr), m_color(Qt::GlobalColor::black), m_thickness(0)
{
}

RectangleShape::RectangleShape(int x, int y, int width, int height, QMainWindow * surface, Qt::GlobalColor color, int thickness)
	: AbstractItem(x, y, width, height, surface), m_thickness(thickness), m_color(color)
{
}

void RectangleShape::DrawItem()
{
	m_painter = new QPainter(m_surface);
	m_painter->setRenderHint(QPainter::Antialiasing, true);
	m_painter->setBrush(QBrush(m_color));

	QPen pen;
	pen.setColor(m_color);
	pen.setWidth(m_thickness);

	m_painter->setPen(pen);
	m_painter->drawRect(m_x, m_y, m_width, m_height);
}

void RectangleShape::HideItem()
{
	m_color = Qt::GlobalColor::white;
}


