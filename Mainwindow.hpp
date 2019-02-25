#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include <QHBoxLayout>
#include <QMenuBar>
#include <QFile>
#include <QDir>
#include <QMessageBox>
#include <QApplication>

#include "Code.hpp"


class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow (QWidget *parent = 0);
    ~MainWindow ();

public slots:
    void check ();

private:
    void build ();
    bool runTest ();


    Code *m_testGenerator;
    Code *m_correctCode;
    Code *m_codeToCheck;
};

#endif // MAINWINDOW_HPP
