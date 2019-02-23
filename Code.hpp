#ifndef CODE_HPP
#define CODE_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLineEdit>
#include <QLabel>


class Code : public QWidget
{
    Q_OBJECT

public:
    explicit Code (const QString &name, QWidget *parent=0);

    void setLanguage (const QString &language);

private:
    QTextEdit *m_code;
    QLineEdit *m_buildCommand;
    QLineEdit *m_runCommand;
};

#endif // CODE_HPP
