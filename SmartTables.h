#pragma once

#include <QtWidgets/QMainWindow>
#include "TextLabel.h"
#include "ui_SmartTables.h"
#include "RectangleShape.h"
#include "CustomButton.h"

class SmartTables : public QMainWindow
{
    Q_OBJECT

public:
    SmartTables(QWidget *parent = nullptr);
    ~SmartTables();

    virtual void paintEvent(QPaintEvent * event);
    void resizeEvent(QResizeEvent * event);

private:
    Ui::SmartTablesClass ui; // idk what it is

    const int MAX_WIDTH = 1440, MAX_HEIGHT = 1024;
    const int MIN_WIDTH = 800, MIN_HEIHGT = 600;

    RectangleShape * TopBox;
    RectangleShape * ExternalNoTable;
    RectangleShape * InternalNoTable;
    RectangleShape * BackgroungBox;

    TextLabel * NoTable;

    CustomButton * NewColButton;
    CustomButton * ProceedButton;
};
