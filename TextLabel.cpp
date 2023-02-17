#include "TextLabel.h"

TextLabel::TextLabel()
	: m_text(""), m_x(0), m_y(0), m_width(0), m_height(0), m_fontSize(0), m_textColor(Qt::GlobalColor::black), m_surface(nullptr)
{
	m_label = new QLabel(nullptr);
}

TextLabel::TextLabel(QString text, int x, int y, int width, int height, int fontSize, Qt::GlobalColor color, QMainWindow * surface)
	: m_text(text), m_x(x), m_y(y), m_width(width), m_height(height), m_fontSize(fontSize), m_textColor(color), m_surface(surface)
{
	m_label = new QLabel(m_surface);

	m_label->setGeometry(m_x, m_y, m_width, m_height);
	
	QFont font = m_label->font();
	font.setPointSize(m_fontSize);
	m_label->setFont(font);

	QString format("<font color='%1'>" + m_text + "</font>");
	m_label->setText(format.arg(m_textColor.name(), m_text));
}

void TextLabel::DrawLabel()
{
	m_label->show();
}

