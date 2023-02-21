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

    NewColButton = new CustomButton(198, 346, 404, 66, this, "Add a new table");
    connect(NewColButton->getButtonComponent(), &QPushButton::released, this, &SmartTables::StartWork);

    ProceedButton = new CustomButton(182, 531, 436, 49, this, "Proceed");

    MainTable = new Table(TABLE_X, TABLE_Y, TABLE_W, TABLE_H, this);

    AddRow = new CustomButton(TABLE_X - (BUTTON_SIZE + SPACE), TABLE_Y, BUTTON_SIZE, BUTTON_SIZE, this, "+R");
    connect(AddRow->getButtonComponent(), &QPushButton::released, MainTable, &Table::AddRow);
    AddCol = new CustomButton(TABLE_X - (BUTTON_SIZE + SPACE), TABLE_Y + (BUTTON_SIZE + SPACE), BUTTON_SIZE, BUTTON_SIZE, this, "+C");
    connect(AddCol->getButtonComponent(), &QPushButton::released, MainTable, &Table::AddCol);
    RemoveRow = new CustomButton(TABLE_X - (BUTTON_SIZE + SPACE), TABLE_Y + 2 * (BUTTON_SIZE + SPACE), BUTTON_SIZE, BUTTON_SIZE, this, "-R");
    connect(RemoveRow->getButtonComponent(), &QPushButton::released, MainTable, &Table::RemoveRow);
    RemoveCol = new CustomButton(TABLE_X - (BUTTON_SIZE + SPACE), TABLE_Y + 3 * (BUTTON_SIZE + SPACE), BUTTON_SIZE, BUTTON_SIZE, this, "-C");
    connect(RemoveCol->getButtonComponent(), &QPushButton::released, MainTable, &Table::RemoveCol);

    AddRow->HideItem();
    AddCol->HideItem();
    RemoveRow->HideItem();
    RemoveCol->HideItem();

    DrawStartInterface = true;
}

SmartTables::~SmartTables()
{}

void SmartTables::paintEvent(QPaintEvent * event)
{
    // layer 1
    BackgroungBox->DrawItem();
    
    // layer 2
    TopBox->DrawItem();

    if (DrawStartInterface)
    {
        // layer 3
        ExternalNoTable->DrawItem();
        InternalNoTable->DrawItem();
        
        /* also NoTable text label is drawing here */
    }
}

void SmartTables::StartWork()
{
    HideStartInterface();
    CreateNewTable();
}

void SmartTables::HideStartInterface()
{
    DrawStartInterface = false;

    NoTable->HideItem();
    NewColButton->HideItem();

    repaint();
}

void SmartTables::CreateNewTable()
{
    MainTable->DrawItem();
    AddRow->DrawItem();
    AddCol->DrawItem();
    RemoveRow->DrawItem();
    RemoveCol->DrawItem();
}
