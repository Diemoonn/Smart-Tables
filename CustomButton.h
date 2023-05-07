#pragma once

#include "AbstractItem.h"
#include <qpushbutton.h>

class CustomButton : AbstractItem
{
public:
	CustomButton();
	CustomButton(int x, int y, int width, int height, QMainWindow * surface, QString text);

	virtual void DrawItem();
	virtual void HideItem();

	QPushButton * getButtonComponent();

private:
	QPushButton * m_button;
	QString m_text;
};

