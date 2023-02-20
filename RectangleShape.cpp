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
	QPainter painter(m_surface);
	painter.setRenderHint(QPainter::Antialiasing, true);
	painter.setBrush(QBrush(m_color));

	QPen pen;
	pen.setColor(m_color);
	pen.setWidth(m_thickness);

	painter.setPen(pen);
	painter.drawRect(m_x, m_y, m_width, m_height);
}

void RectangleShape::ResizeItem(float wK, float hK)
{
	m_x *= wK;
	m_y *= hK;
	m_width *= wK;
	m_height *= hK;
}


