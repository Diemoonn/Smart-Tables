#include "ResultWindow.h"

ResultWindow::ResultWindow(int columns, QWidget * parent)
	: QMainWindow(parent)
{
	setFixedSize(MIN_WIDTH, MIN_HEIGHT);
	setWindowTitle("Results");

	m_PrevButton = new CustomButton(28, 520, 110, 68, this, "Prev");
	m_NextButton = new CustomButton(659, 520, 113, 68, this, "Next");

	m_ValueLabel = new TextLabel(282, 32, 235, 68, this, "", 40, Qt::GlobalColor::white);

	m_InstrumentError = new TextLabel(28, 132, 357, 68, this, "", 40, Qt::GlobalColor::black);
	m_ConfidenceLevel = new TextLabel(28, 232, 357, 68, this, "", 40, Qt::GlobalColor::black);
	m_StudentKoeff = new TextLabel(28, 332, 357, 68, this, "", 40, Qt::GlobalColor::black);
	m_MiddleValue = new TextLabel(28, 432, 357, 68, this, "", 40, Qt::GlobalColor::black);

	m_StandartError = new TextLabel(415, 132, 357, 68, this, "", 40, Qt::GlobalColor::black);
	m_RandomError = new TextLabel(415, 232, 357, 68, this, "", 40, Qt::GlobalColor::black);
	m_AbsoluteError = new TextLabel(415, 332, 357, 68, this, "", 40, Qt::GlobalColor::black);
	m_RelativeError = new TextLabel(415, 432, 357, 68, this, "", 40, Qt::GlobalColor::black);

	m_valueCount = 0;
	m_globalIter = 0;

	connect(m_PrevButton->getButtonComponent(), &QPushButton::released, this, &ResultWindow::Prev);
	connect(m_NextButton->getButtonComponent(), &QPushButton::released, this, &ResultWindow::Next);

	show();
}

ResultWindow::~ResultWindow()
{
	
}

void ResultWindow::ParseData(std::string value, std::vector<double> results)
{
	m_valueNames.push_back(value);

	std::vector<double> temp;
	for (int i = 0; i < RESULTS; i++)
		temp.push_back(results[i]);

	m_data.push_back(temp);

	m_valueCount++;

	Setup();
}

void ResultWindow::Next() //TODO: твоя мать - недопустимый параметр функции
{
	if (m_globalIter >= m_valueCount - 1)
		return;
	
	m_globalIter++;
	Setup(m_globalIter);
}

void ResultWindow::Prev()
{
	if (m_globalIter == 0)
		return;
	
	m_globalIter--;
	Setup(m_globalIter);
}

void ResultWindow::Setup(int i)
{
	m_ValueLabel->getLabelComponent()->setText(QString::fromStdString(m_valueNames[i]));

	m_InstrumentError->getLabelComponent()->setText(QString::number(m_data[i][0]));
	m_ConfidenceLevel->getLabelComponent()->setText(QString::number(m_data[i][1]));
	m_StudentKoeff->getLabelComponent()->setText(QString::number(m_data[i][2]));
	m_MiddleValue->getLabelComponent()->setText(QString::number(m_data[i][3]));
	m_StandartError->getLabelComponent()->setText(QString::number(m_data[i][4]));
	m_RandomError->getLabelComponent()->setText(QString::number(m_data[i][5]));
	m_AbsoluteError->getLabelComponent()->setText(QString::number(m_data[i][6]));
	m_RelativeError->getLabelComponent()->setText(QString::number(m_data[i][7]));
}
