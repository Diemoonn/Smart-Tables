#pragma once

#include <QtWidgets/QMainWindow>
#include <vector>
#include "CustomButton.h"
#include "TextLabel.h"

namespace Ui
{
	class ResultWindow;
}

class ResultWindow : public QMainWindow
{
	Q_OBJECT;

public:
	ResultWindow(int columns = 1, QWidget * parent = nullptr);
	~ResultWindow();

	void ParseData(std::string value, std::vector<double> results);
	void Next();
	void Prev();

private:
	void Setup(int i = 0);

	const int MIN_WIDTH = 800, MIN_HEIGHT = 600, RESULTS = 8;

	int m_valueCount, m_globalIter;

	CustomButton * m_PrevButton;
	CustomButton * m_NextButton;

	std::vector<std::vector<double>> m_data;
	std::vector<std::string> m_valueNames;

	TextLabel * m_ValueLabel, * m_InstrumentError,
		* m_ConfidenceLevel, * m_StudentKoeff,
		* m_MiddleValue, * m_StandartError,
		* m_RandomError, * m_AbsoluteError,
		* m_RelativeError;
};

