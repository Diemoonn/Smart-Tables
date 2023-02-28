#include "ResultWindow.h"

ResultWindow::ResultWindow(QWidget * parent)
	: QWidget(parent), ui(new Ui::ResultWindow)
{
	ui->setupUi(this);
}

ResultWindow::~ResultWindow()
{
	delete ui;
}
