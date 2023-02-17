#include "SmartTables.h"

SmartTables::SmartTables(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    setFixedSize(WIDTH, HEIGHT);

    TopBox = new RectangleShape(1440, 117, 0, 0, Qt::GlobalColor::darkMagenta, this);
    ExternalNoTable = new RectangleShape(845, 597, 298, 214, Qt::GlobalColor::gray, this);
    InternalNoTable = new RectangleShape(787, 545, 330, 240, Qt::GlobalColor::white, this);

    Label = new TextLabel("There is no table yet...", 457, 305, 525, 61, 38, Qt::GlobalColor::lightGray, this);
}

SmartTables::~SmartTables()
{}

void SmartTables::paintEvent(QPaintEvent * event)
{
    TopBox->DrawShape();

    ExternalNoTable->DrawShape();
    InternalNoTable->DrawShape();

    Label->DrawLabel();
}
