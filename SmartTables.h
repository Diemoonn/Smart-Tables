#pragma once

#include <QtWidgets/QMainWindow>
#include "TextLabel.h"
#include "ui_SmartTables.h"
#include "RectangleShape.h"

class SmartTables : public QMainWindow
{
    Q_OBJECT

public:
    SmartTables(QWidget *parent = nullptr);
    ~SmartTables();

    virtual void paintEvent(QPaintEvent * event);

private:
    Ui::SmartTablesClass ui; // idk what it is

    const int WIDTH = 1440;
    const int HEIGHT = 1024;

    RectangleShape * TopBox;
    RectangleShape * ExternalNoTable;
    RectangleShape * InternalNoTable;

    TextLabel * Label;
};
