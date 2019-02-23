#include "Mainwindow.hpp"

MainWindow::MainWindow (QWidget *parent) :
    QMainWindow(parent)
{
    showMaximized();

    QWidget *centralWidget = new QWidget;
    setCentralWidget(centralWidget);

    QHBoxLayout *layout = new QHBoxLayout;
    centralWidget->setLayout(layout);

    layout->addWidget(new Code("Test generator"));
    layout->addWidget(new Code("Correct code"));
    layout->addWidget(new Code("Code to check"));
}

MainWindow::~MainWindow ()
{

}
