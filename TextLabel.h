#pragma once

#include <qlabel.h>
#include <QtWidgets/QMainWindow>

class TextLabel
{
public:
	TextLabel();
	TextLabel(QString text, int x, int y, int width, int height, int fontSize, Qt::GlobalColor textColor, QMainWindow * surface);

	void DrawLabel();

private:
	int m_x, m_y;
	int m_fontSize, m_width, m_height;
	QMainWindow * m_surface;
	QLabel * m_label;
	QColor m_textColor;
	QString m_text;
};

