#include "SmartTables.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); // basic qt class that controls this whole applicaion
    SmartTables w; // main application window (UI)

    w.show(); // actually shows SmartTables window
    return a.exec(); // here the main loop of processing events starts (user interactions included) 
}
