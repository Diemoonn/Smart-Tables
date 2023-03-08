#include "ResultWindow.h"
#include "stringProcessor.h"

ResultWindow::ResultWindow(int columns, QWidget * parent)
	: QMainWindow(parent)
{
	setFixedSize(MIN_WIDTH, MIN_HEIGHT);
	setWindowTitle(text(16));

	m_PrevButton = new CustomButton(28, 520, 110, 68, this, text(17));
	m_NextButton = new CustomButton(659, 520, 113, 68, this, text(18));

	m_ValueLabel = new TextLabel(282, 32, 235, 68, this, "", 40, Qt::GlobalColor::white);

	m_InstrumentError = new TextLabel(28, 132, 210, 44, this, text(19), 10, Qt::GlobalColor::black);
	m_ConfidenceLevel = new TextLabel(28, 232, 210, 44, this, text(20), 10, Qt::GlobalColor::black);
	m_StudentKoeff = new TextLabel(28, 332, 210, 44, this, text(21), 10, Qt::GlobalColor::black);
	m_MiddleValue = new TextLabel(28, 432, 210, 44, this, text(22), 10, Qt::GlobalColor::black);

	m_StandartError = new TextLabel(415, 132, 210, 44, this, text(23), 10, Qt::GlobalColor::black);
	m_RandomError = new TextLabel(415, 232, 210, 44, this, text(24), 10, Qt::GlobalColor::black);
	m_AbsoluteError = new TextLabel(415, 332, 210, 44, this, text(25), 10, Qt::GlobalColor::black);
	m_RelativeError = new TextLabel(415, 432, 210, 44, this, text(26), 10, Qt::GlobalColor::black);

	m_result1 = new TextLabel(240, 132, 113, 44, this, "", 20, Qt::GlobalColor::black);
	m_result2 = new TextLabel(240, 232, 113, 44, this, "", 20, Qt::GlobalColor::black);
	m_result3 = new TextLabel(240, 332, 113, 44, this, "", 20, Qt::GlobalColor::black);
	m_result4 = new TextLabel(240, 432, 113, 44, this, "", 20, Qt::GlobalColor::black);

	m_result5 = new TextLabel(613, 132, 113, 44, this, "", 20, Qt::GlobalColor::black);
	m_result6 = new TextLabel(613, 232, 113, 44, this, "", 20, Qt::GlobalColor::black);
	m_result7 = new TextLabel(613, 332, 113, 44, this, "", 20, Qt::GlobalColor::black);
	m_result8 = new TextLabel(613, 432, 113, 44, this, "", 20, Qt::GlobalColor::black);

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

void ResultWindow::Next()
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

	m_result1->getLabelComponent()->setText(QString::number(m_data[i][0]));
	m_result2->getLabelComponent()->setText(QString::number(m_data[i][1]));
	m_result3->getLabelComponent()->setText(QString::number(m_data[i][2]));
	m_result4->getLabelComponent()->setText(QString::number(m_data[i][3]));
	m_result5->getLabelComponent()->setText(QString::number(m_data[i][4]));
	m_result6->getLabelComponent()->setText(QString::number(m_data[i][5]));
	m_result7->getLabelComponent()->setText(QString::number(m_data[i][6]));
	m_result8->getLabelComponent()->setText(QString::number(m_data[i][7]));
}
