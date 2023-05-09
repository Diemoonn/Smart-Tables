/********************************************************************************
** Form generated from reading UI file 'SmartTables.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SMARTTABLES_H
#define UI_SMARTTABLES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SmartTablesClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *SmartTablesClass)
    {
        if (SmartTablesClass->objectName().isEmpty())
            SmartTablesClass->setObjectName(QStringLiteral("SmartTablesClass"));
        SmartTablesClass->resize(600, 400);
        menuBar = new QMenuBar(SmartTablesClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        SmartTablesClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(SmartTablesClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        SmartTablesClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(SmartTablesClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        SmartTablesClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SmartTablesClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        SmartTablesClass->setStatusBar(statusBar);

        retranslateUi(SmartTablesClass);

        QMetaObject::connectSlotsByName(SmartTablesClass);
    } // setupUi

    void retranslateUi(QMainWindow *SmartTablesClass)
    {
        SmartTablesClass->setWindowTitle(QApplication::translate("SmartTablesClass", "SmartTables", 0));
    } // retranslateUi

};

namespace Ui {
    class SmartTablesClass: public Ui_SmartTablesClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SMARTTABLES_H
