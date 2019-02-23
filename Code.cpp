#include "Code.hpp"

Code::Code (const QString &name, QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout;
    setLayout(layout);

    layout->addWidget(new QLabel(name));

    layout->addWidget(new QTextEdit);
}
