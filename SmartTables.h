#pragma once

#include <QtWidgets/QMainWindow>
#include "TextLabel.h"
#include "ui_SmartTables.h"
#include "RectangleShape.h"
#include "CustomButton.h"
#include "Table.h"

class SmartTables : public QMainWindow
{
    Q_OBJECT

public:
    SmartTables(QWidget *parent = nullptr);
    ~SmartTables();

    virtual void paintEvent(QPaintEvent * event);

private:
    void HideStartInterface();
    void CreateNewTable();
    void StartWork();
    void Proceed();

    Ui::SmartTablesClass ui;

    bool DrawStartInterface;

    const int MAX_WIDTH = 1440, MAX_HEIGHT = 1024;
    const int MIN_WIDTH = 800, MIN_HEIHGT = 600;
    const int TABLE_X = 82, TABLE_Y = 105, TABLE_W = 636, TABLE_H = 330;
    const int BUTTON_SIZE = 50;
    const int SPACE = 10;

    RectangleShape * TopBox;
    RectangleShape * ExternalNoTable;
    RectangleShape * InternalNoTable;
    RectangleShape * BackgroungBox;

    TextLabel * NoTable;

    CustomButton * NewColButton, * ProceedButton;
    CustomButton * AddRow, * AddCol, * RemoveRow, * RemoveCol;

    Table * MainTable;
};
