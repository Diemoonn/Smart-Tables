#pragma once

#include <QtWidgets/QMainWindow>

class AbstractItem : public QObject
{
public:
	AbstractItem(int x, int y, int width, int height, QMainWindow * surface);

	virtual void DrawItem() = 0;
	virtual void HideItem() = 0;

protected:
	int m_x, m_y, m_width, m_height;
	QMainWindow * m_surface;

};

