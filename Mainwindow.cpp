#include "Mainwindow.hpp"

MainWindow::MainWindow (QWidget *parent) :
    QMainWindow(parent)
{
    showMaximized();

    QWidget *centralWidget = new QWidget;
    setCentralWidget(centralWidget);

    QHBoxLayout *layout = new QHBoxLayout;
    centralWidget->setLayout(layout);

    m_testGenerator = new Code ("Test generator");
    m_testGenerator->setLanguage("python3");
    layout->addWidget(m_testGenerator);

    m_correctCode = new Code ("Correct code");
    m_correctCode->setLanguage("c++");
    layout->addWidget(m_correctCode);

    m_codeToCheck = new Code ("Code to check");
    m_codeToCheck->setLanguage("c++");
    layout->addWidget(m_codeToCheck);
}

MainWindow::~MainWindow ()
{

}
