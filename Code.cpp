#include "Code.hpp"

Code::Code (const QString &name, QWidget *parent) :
    QWidget(parent)
{
    QVBoxLayout *layout = new QVBoxLayout;
    setLayout(layout);

    layout->addWidget(new QLabel(name));

    m_code = new QTextEdit;
    layout->addWidget(m_code);

    layout->addWidget(new QLabel("Build command"));

    m_buildCommand = new QLineEdit;
    layout->addWidget(m_buildCommand);

    layout->addWidget(new QLabel("Run command"));

    m_runCommand = new QLineEdit;
    layout->addWidget(m_runCommand);
}

void Code::setLanguage (const QString &language)
{
    if (language == "c++") {
        m_buildCommand->setText("mv source source.cpp && g++ -O3 source.cpp -o prog");
        m_runCommand->setText("./prog < test");
    }
    else if (language == "python3") {
        m_buildCommand->setText("mv source source.py");
        m_runCommand->setText("python3 source.py < test");
    }
}
