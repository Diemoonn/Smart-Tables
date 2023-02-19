#include "SmartTables.h"

SmartTables::SmartTables(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    setFixedSize(WIDTH, HEIGHT);

    TopBox = new RectangleShape(0, 0, 1440, 117, this, Qt::GlobalColor::darkMagenta);
    ExternalNoTable = new RectangleShape(298, 214, 845, 597, this, Qt::GlobalColor::gray);
    InternalNoTable = new RectangleShape(330, 240, 787, 545, this, Qt::GlobalColor::white);

    NoTable = new TextLabel(457, 305, 525, 61, this, "There is no table yet...", 38, Qt::GlobalColor::lightGray);
}

SmartTables::~SmartTables()
{}

void SmartTables::paintEvent(QPaintEvent * event)
{
    TopBox->DrawItem();

    ExternalNoTable->DrawItem();
    InternalNoTable->DrawItem();

    NoTable->DrawItem();
}
