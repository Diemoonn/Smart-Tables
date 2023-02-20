#include "SmartTables.h"

SmartTables::SmartTables(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    // setMinimumSize(MIN_WIDTH, MIN_HEIHGT);
    // setMaximumSize(MAX_WIDTH, MAX_HEIGHT);
    // resize(MIN_WIDTH, MIN_HEIHGT);
    setFixedSize(MIN_WIDTH, MIN_HEIHGT);

    TopBox = new RectangleShape(0, 0, 800, 71, this, Qt::GlobalColor::darkMagenta);
    ExternalNoTable = new RectangleShape(86, 155, 628, 299, this, Qt::GlobalColor::gray);
    InternalNoTable = new RectangleShape(99, 165, 603, 279, this, Qt::GlobalColor::white);
    BackgroungBox = new RectangleShape(0, 0, MAX_WIDTH, MAX_HEIGHT, this, Qt::GlobalColor::white);

    NoTable = new TextLabel(150, 185, 528, 58, this, "There is no table yet...", 38, Qt::GlobalColor::lightGray);

    NewColButton = new CustomButton(198, 346, 404, 66, this, "Add a new column");
    ProceedButton = new CustomButton(182, 531, 436, 49, this, "Proceed");
}

SmartTables::~SmartTables()
{}

void SmartTables::paintEvent(QPaintEvent * event)
{
    // layer 1
    BackgroungBox->DrawItem();
    
    // layer 2
    TopBox->DrawItem();

    // layer 3
    ExternalNoTable->DrawItem();
    InternalNoTable->DrawItem();

    // layer 4
    NoTable->DrawItem();
}

void SmartTables::resizeEvent(QResizeEvent * event)
{
    int w = this->geometry().width();
    int h = this->geometry().height();

    /*new size / last size*/

    QMainWindow::resizeEvent(event);
}
