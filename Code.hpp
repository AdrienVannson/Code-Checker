#ifndef CODE_HPP
#define CODE_HPP

#include <QWidget>
#include <QVBoxLayout>
#include <QTextEdit>
#include <QLabel>


class Code : public QWidget
{
    Q_OBJECT

public:
    explicit Code (const QString &name, QWidget *parent=0);



private:
    QTextEdit *m_code;

};

#endif // CODE_HPP
