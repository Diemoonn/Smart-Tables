#include "CustomButton.h"

CustomButton::CustomButton()
	: AbstractItem(0, 0, 0, 0, nullptr), m_text("")
{
	m_button = new QPushButton();
}

CustomButton::CustomButton(int x, int y, int width, int height, QMainWindow * surface, QString text)
	: AbstractItem(x, y, width, height, surface), m_text(text)
{
	m_button = new QPushButton(m_text, m_surface);
	m_button->setGeometry(m_x, m_y, m_width, m_height);
}

void CustomButton::DrawItem()
{
	m_button->show();
}

void CustomButton::HideItem()
{
	m_button->hide();
}

QPushButton * CustomButton::getButtonComponent()
{
	return m_button;
}
