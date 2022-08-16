#include "calc.h"

double num_first;

Calculator::Calculator(QWidget *parent):
    zeroBtn(new QPushButton("0")),
    oneBtn(new QPushButton("1")),
    twoBtn(new QPushButton("2")),
    threeBtn(new QPushButton("3")),
    fourBtn(new QPushButton("4")),
    fiveBtn(new QPushButton("5")),
    sixBtn(new QPushButton("6")),
    sevenBtn(new QPushButton("7")),
    eightBtn(new QPushButton("8")),
    nineBtn(new QPushButton("9")),
    pointBtn(new QPushButton(".")),
    equalBtn(new QPushButton("=")),
    addBtn(new QPushButton("+")),
    subsBtn(new QPushButton("-")),
    mulBtn(new QPushButton("*")),
    divBtn(new QPushButton("/")),    
    clearBtn(new QPushButton("CLR")),
    plusMinusBtn(new QPushButton("+/-")),
    display(new QLineEdit())
{
    QGridLayout *mainLay = new QGridLayout;
    // First row
    mainLay->addWidget(sevenBtn, 2, 1);
    mainLay->addWidget(eightBtn, 2, 2);
    mainLay->addWidget(nineBtn, 2, 3);
    mainLay->addWidget(addBtn, 2, 4);
    // Second row
    mainLay->addWidget(fourBtn, 3, 1);
    mainLay->addWidget(fiveBtn, 3, 2);
    mainLay->addWidget(sixBtn, 3, 3);
    mainLay->addWidget(subsBtn, 3, 4);
    // Third row
    mainLay->addWidget(oneBtn, 4, 1);
    mainLay->addWidget(twoBtn, 4, 2);
    mainLay->addWidget(threeBtn, 4, 3);
    mainLay->addWidget(mulBtn, 4, 4);
    // Fourth row
    mainLay->addWidget(zeroBtn, 5, 1);
    mainLay->addWidget(pointBtn, 5, 2);
    mainLay->addWidget(equalBtn, 5, 3);
    mainLay->addWidget(divBtn, 5, 4);
    // Display
    display->setReadOnly(true);
    display->setAlignment(Qt::AlignRight);
    mainLay->addWidget(display, 1, 1, 1, 2);
    // Clear
    mainLay->addWidget(clearBtn, 1, 3);
    // Clear
    mainLay->addWidget(plusMinusBtn, 1, 4);

    connect(zeroBtn, SIGNAL(clicked()), this, SLOT(digitSlot()));
    connect(oneBtn, SIGNAL(clicked()), this, SLOT(digitSlot()));
    connect(twoBtn, SIGNAL(clicked()), this, SLOT(digitSlot()));
    connect(threeBtn, SIGNAL(clicked()), this, SLOT(digitSlot()));
    connect(fourBtn, SIGNAL(clicked()), this, SLOT(digitSlot()));
    connect(fiveBtn, SIGNAL(clicked()), this, SLOT(digitSlot()));
    connect(sixBtn, SIGNAL(clicked()), this, SLOT(digitSlot()));
    connect(sevenBtn, SIGNAL(clicked()), this, SLOT(digitSlot()));
    connect(eightBtn, SIGNAL(clicked()), this, SLOT(digitSlot()));
    connect(nineBtn, SIGNAL(clicked()), this, SLOT(digitSlot()));
    connect(pointBtn, SIGNAL(clicked()), this, SLOT(pointSlot()));
    connect(addBtn, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(subsBtn, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(mulBtn, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(plusMinusBtn, SIGNAL(clicked()), this, SLOT(plusMinusSlot()));
    connect(divBtn, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(equalBtn, SIGNAL(clicked()), this, SLOT(equalSlot()));
    connect(clearBtn, SIGNAL(clicked()), this, SLOT(clearSlot()));

    addBtn->setCheckable(true);
    subsBtn->setCheckable(true);
    mulBtn->setCheckable(true);
    divBtn->setCheckable(true);

    setLayout(mainLay);
}
Calculator:: ~Calculator(){}
void Calculator::digitSlot()
{    
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if(display->text().contains(".") && button->text() == "0")
    {
        new_label = display->text() + button->text();
    }
    else
    {
        all_numbers = (display->text() + button->text()).toDouble();
        new_label = QString::number(all_numbers, 'g', 15);
    }
    display->setText(new_label);
}

void Calculator::pointSlot()
{
    if(!(display->text().contains('.')))
        display->setText(display->text() + ".");
}

void Calculator::plusMinusSlot()
{
    QPushButton *button = (QPushButton *)sender();
    double all_numbers;
    QString new_label;

    if(button->text() == "+/-")
    {
        all_numbers = (display->text()).toDouble();
        all_numbers = all_numbers * (-1);
        new_label = QString::number(all_numbers, 'g', 15);
        display->setText(new_label);
    }

}

void Calculator::math_operations()
{
    QPushButton *button = (QPushButton *)sender();

    num_first = display->text().toDouble();
    display->setText("");
    button->setCheckable(true);


}

void Calculator::equalSlot()
{
    double labelNumber, num_second;
    QString new_label;

    num_second = display->text().toDouble();

    if(addBtn->isChecked())
    {
        labelNumber = num_first + num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        display->setText(new_label);
        addBtn->setChecked(false);
    }
    else if(subsBtn->isChecked())
    {
        labelNumber = num_first - num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        display->setText(new_label);
        subsBtn->setChecked(false);
    }
    else if(mulBtn->isChecked())
    {
        labelNumber = num_first * num_second;
        new_label = QString::number(labelNumber, 'g', 15);
        display->setText(new_label);
        mulBtn->setChecked(false);
    }
    else if(divBtn->isChecked())
    {
        if(num_second == 0)
        {
            display->setText("0");
        }
        else
        {
            labelNumber = num_first / num_second;
            new_label = QString::number(labelNumber, 'g', 15);
            display->setText(new_label);
        }
        divBtn->setChecked(false);
    }
}

void Calculator::clearSlot()
{
    addBtn->setChecked(false);
    subsBtn->setChecked(false);
    mulBtn->setChecked(false);
    divBtn->setChecked(false);
    display->setText("0");
}


