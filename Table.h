#pragma once

#include <qtablewidget.h>
#include <QtWidgets/QMainWindow>
#include <qinputdialog.h>
#include <qmessagebox.h>
#include <qdoublespinbox>
#include <cmath>
#include "AbstractItem.h"
#include "ResultWindow.h"

class Table : public AbstractItem
{
public:
	Table(int x, int y, int width, int height, QMainWindow * surface, int rows = 1, int columns = 0);

	virtual void DrawItem();
	virtual void HideItem();
	
	void AddRow();
	void AddCol();
	void RemoveRow();
	void RemoveCol();
	void ProceedTable();

private:
	inline double GetCellValue(int row, int col) 
	{ return qobject_cast<QDoubleSpinBox*>(m_table->cellWidget(row, col))->value(); }

	double GetStudent(int n, double confidLevel);

	int m_rows, m_cols;

	QTableWidget * m_table;

	ResultWindow * m_result;
};

