#include "Mainwindow.hpp"

MainWindow::MainWindow (QWidget *parent) :
    QMainWindow(parent)
{
    showMaximized();

    // Create menu
    QMenu *projectMenu = menuBar()->addMenu(tr("&Project"));

    QAction *checkAction = new QAction(tr("&Check"), this);
    connect(checkAction, &QAction::triggered, this, &MainWindow::check);
    projectMenu->addAction(checkAction);


    // Create widgets
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
    // Clear
    system("rm -r test_generator");
    system("rm -r correct_code");
    system("rm -r code_to_check");
}

void MainWindow::check ()
{
    build();
    qApp->processEvents();

    while (!runTest()) {
        qApp->processEvents();
    }
}

void MainWindow::build ()
{
    // Test generator
    system("mkdir test_generator");
    QDir::setCurrent("test_generator");

    QFile source1 ("source");
    source1.open(QIODevice::WriteOnly);
    source1.write(m_testGenerator->code().toUtf8());
    source1.close();

    system(m_testGenerator->buildCommand().toUtf8());

    QDir::setCurrent("..");

    // Correct code
    system("mkdir correct_code");
    QDir::setCurrent("correct_code");

    QFile source2 ("source");
    source2.open(QIODevice::WriteOnly);
    source2.write(m_correctCode->code().toUtf8());
    source2.close();

    system(m_correctCode->buildCommand().toUtf8());

    QDir::setCurrent("..");

    // Code to check
    system("mkdir code_to_check");
    QDir::setCurrent("code_to_check");

    QFile source3 ("source");
    source3.open(QIODevice::WriteOnly);
    source3.write(m_codeToCheck->code().toUtf8());
    source3.close();

    system(m_codeToCheck->buildCommand().toUtf8());

    QDir::setCurrent("..");
}

// Returns true if a test that produces different outputs have been found
bool MainWindow::runTest ()
{
    QDir::setCurrent("test_generator");
    system( (m_testGenerator->runCommand() + " > test").toUtf8() );
    QDir::setCurrent("..");

    QDir::setCurrent("correct_code");
    system( (m_correctCode->runCommand() + " < ../test_generator/test > output").toUtf8() );
    QDir::setCurrent("..");

    QDir::setCurrent("code_to_check");
    system( (m_codeToCheck->runCommand() + " < ../test_generator/test > output").toUtf8() );
    QDir::setCurrent("..");

    const int result = system("diff -Z correct_code/output code_to_check/output");

    if (WEXITSTATUS(result) == 1) { // Files differ
        system("cp test_generator/test test");

        QMessageBox msgBox;
        msgBox.setText("Test found!");
        msgBox.exec();

        return true;
    }

    return false;
}
