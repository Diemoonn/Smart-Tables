#include "AbstractItem.h"

AbstractItem::AbstractItem(int x, int y, int width, int height, QMainWindow * surface)
	: m_x(x), m_y(y), m_width(width), m_height(height), m_surface(surface)
{
}
