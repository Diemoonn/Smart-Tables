#pragma once

#include <qlabel.h>
#include "AbstractItem.h"

class TextLabel : public AbstractItem
{
public:
	TextLabel();
	TextLabel(int x, int y, int width, int height, QMainWindow * surface, QString text, int fontSize, Qt::GlobalColor textColor);
	virtual void DrawItem();

private:
	int m_fontSize;
	QLabel * m_label;
	QColor m_textColor;
	QString m_text;
};

