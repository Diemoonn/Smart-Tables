#include "TextLabel.h"

TextLabel::TextLabel()
	: AbstractItem(0, 0, 0, 0, nullptr), m_text(""), m_fontSize(0), m_textColor(Qt::GlobalColor::black)
{
	m_label = new QLabel(nullptr);
}

TextLabel::TextLabel(int x, int y, int width, int height, QMainWindow * surface, QString text, int fontSize, Qt::GlobalColor textColor)
	: AbstractItem(x, y, width, height, surface), m_text(text), m_fontSize(fontSize), m_textColor(textColor)
{
	m_label = new QLabel(m_surface);

	m_label->setGeometry(m_x, m_y, m_width, m_height);

	QFont font = m_label->font();
	font.setPointSize(m_fontSize);
	//QFont font("Arial", m_fontSize);
	m_label->setFont(font);

	QString format("<font color='%1'>" + m_text + "</font>");
	m_label->setText(format.arg(m_textColor.name(), m_text));
}

void TextLabel::DrawItem()
{
	m_label->show();
}

void TextLabel::HideItem()
{
	m_label->hide();
}

