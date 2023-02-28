#pragma once

#include <QWidget>

class ResultWindow : public QWidget
{
	Q_OBJECT;

public:
	ResultWindow(QWidget * parent = nullptr);
	~ResultWindow();

private:
	Ui::ResultWindowClass * ui;
};

