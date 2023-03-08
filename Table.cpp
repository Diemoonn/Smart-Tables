#include <fstream>
#include <limits.h>
#include <vector>
#include "Table.h"
#include "stringProcessor.h"

Table::Table(int x, int y, int width, int height, QMainWindow * surface, int rows, int columns)
	: AbstractItem(x, y, width, height, surface), m_rows(rows), m_cols(columns)
{
	m_table = new QTableWidget(m_rows, m_cols, surface);
	m_table->setGeometry(m_x, m_y, m_width, m_height);

	m_table->hide();
}

void Table::DrawItem()
{
	m_table->show();
}

void Table::HideItem()
{
	m_table->hide();
}

void Table::AddRow()
{
	m_table->insertRow(m_table->rowCount());

	QLineEdit *edit = new QLineEdit(m_table);
	edit->setValidator(new QDoubleValidator(edit));

	for (int i = 0; i < m_table->columnCount(); i++)
	{
		QDoubleSpinBox * edit = new QDoubleSpinBox(m_table);
		edit->setDecimals(10);

		m_table->setCellWidget(m_table->rowCount() - 1, i, edit);
	}
}

void Table::AddCol()
{
	QString columnName = QInputDialog::getText(m_surface, text(8), text(9));
	if (columnName.isEmpty())
		return;

	m_table->insertColumn(m_table->columnCount());	
	m_table->setHorizontalHeaderItem(m_table->columnCount() - 1, new QTableWidgetItem(columnName));

	for (int i = 0; i < m_table->rowCount(); i++)
	{
		QDoubleSpinBox * edit = new QDoubleSpinBox(m_table);
		edit->setDecimals(10);

		m_table->setCellWidget(i, m_table->columnCount() - 1, edit);
	}
}

void Table::RemoveRow()
{
	m_table->removeRow(m_table->rowCount() - 1);
}

void Table::RemoveCol()
{
	m_table->removeColumn(m_table->columnCount() - 1);
}

double Table::GetStudent(int n, double confidLevel)
{
	double student = 0.0;
	
	if (confidLevel == 0.9)
	{
		switch (n)
		{
		case 4: student = 2.35; break;
		case 5: student = 2.13; break;
		case 6: student = 2.01; break;
		case 7: student = 1.94; break;
		case 8: student = 1.89; break;
		case 9: student = 1.86; break;
		case 10: student = 1.83; break;
		case 11: student = 1.81; break;
		case 12: student = 1.80; break;
		case 13: student = 1.78; break;
		case 14: student = 1.77; break;
		case 15: student = 1.76; break;
		}
	}
	else if (confidLevel == 0.95)
	{
		switch (n)
		{
		case 4: student = 3.18; break;
		case 5: student = 2.78; break;
		case 6: student = 2.57; break;
		case 7: student = 2.45; break;
		case 8: student = 2.36; break;
		case 9: student = 2.31; break;
		case 10: student = 2.26; break;
		case 11: student = 2.23; break;
		case 12: student = 2.20; break;
		case 13: student = 2.18; break;
		case 14: student = 2.16; break;
		case 15: student = 2.14; break;
		}
	}

	return student;
}

void Table::ProceedTable()
{	
	using namespace std;
	
	int columnNum = 0;
	int n = m_table->rowCount();
	double instrumentError, confidLevel, student;
	double middleValue, deltaSum, standartError, randomError, absoluteError, relativeError;

	ofstream fout("result.txt");

	m_result = new ResultWindow;

	for (int column = 0; column < m_table->columnCount(); column++)
	{
		columnNum = column;
		instrumentError = QInputDialog::getDouble(m_surface, text(10), text(11), 0.0, DBL_MIN, DBL_MAX, 10);
		confidLevel = QInputDialog::getDouble(m_surface, text(12), text(13), 0.0, DBL_MIN, DBL_MAX, 10);

		// calculating a student koeff
		student = GetStudent(n, confidLevel);

		// calculating a middle value
		middleValue = 0.0;
		for (int i = 0; i < n; i++)
			middleValue += GetCellValue(i, columnNum);
		middleValue /= n;

		// calculating a standart error
		deltaSum = 0.0;
		for (int i = 0; i < n; i++)
			deltaSum += pow(GetCellValue(i, columnNum) - middleValue, 2);

		standartError = sqrt(deltaSum / (n * (n - 1)));

		// calculating a random error
		randomError = student * standartError;

		// calculating an absolute error
		absoluteError = sqrt(pow(student * standartError, 2) + pow(instrumentError, 2));

		// TODO: display confidence interval in the end of calculations 

		// calculating a relative error
		relativeError = (absoluteError / middleValue) * 100;

		// this is 'debug only' stuff
		fout << "======\nValue: " << m_table->horizontalHeaderItem(columnNum)->text().toStdString()
			<< "\nInstrument error: " << instrumentError << "\nConfidence level: " << confidLevel
			<< "\nStudent koeff: " << student << "\nMiddle value: " << middleValue
			<< "\nStandart error: " << "sqrt(" << deltaSum << " / " << n << " * " << n - 1 << ") = " << standartError
			<< "\nRadom error: " << randomError
			<< "\nAbsolute error: " << "sqrt(pow(" << student << " * " << standartError << ", 2) + pow(" << instrumentError << ", 2)) = " << absoluteError
			<< "\nRelative error: " << relativeError << "\nFinal value: " << middleValue
			<< " +- " << absoluteError << endl;

		// temporary vector
		vector<double> data; 
		data.push_back(instrumentError);
		data.push_back(confidLevel);
		data.push_back(student);
		data.push_back(middleValue);
		data.push_back(standartError);
		data.push_back(randomError);
		data.push_back(absoluteError);
		data.push_back(relativeError);

		m_result->ParseData(m_table->horizontalHeaderItem(columnNum)->text().toStdString(), data);

		QMessageBox::information(m_surface, text(14), text(15));
	}

	fout.close();
}
