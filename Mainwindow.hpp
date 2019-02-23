#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QHBoxLayout>

#include "Code.hpp"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow (QWidget *parent = 0);
    ~MainWindow ();


private:
    Code *m_testGenerator;
    Code *m_correctCode;
    Code *m_codeToCheck;
};

#endif // MAINWINDOW_HPP
