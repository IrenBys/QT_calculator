#ifndef CALC_H
#define CALC_H

#include <QWidget>
#include <QLabel>
#include <QPushButton>
#include <QLineEdit>
#include <QGridLayout>
#include <QString>
#include <Qt>

class Calculator: public QWidget
{
    Q_OBJECT

public:
    Calculator(QWidget *parent = 0);
    ~Calculator();

private slots:
    void digitSlot();
    void pointSlot();
    void plusMinusSlot();
    void math_operations();
    void equalSlot();
    void clearSlot();
signals:
    void mySignal(int asd);
private:
    QPushButton* zeroBtn;
    QPushButton* oneBtn;
    QPushButton* twoBtn;
    QPushButton* threeBtn;
    QPushButton* fourBtn;
    QPushButton* fiveBtn;
    QPushButton* sixBtn;
    QPushButton* sevenBtn;
    QPushButton* eightBtn;
    QPushButton* nineBtn;
    QPushButton* pointBtn;
    QPushButton* equalBtn;
    QPushButton* addBtn;
    QPushButton* subsBtn;
    QPushButton* mulBtn;
    QPushButton* divBtn;
    QPushButton* clearBtn;
    QPushButton* plusMinusBtn;
    QLineEdit* display;
    QGridLayout* mainLay;
};

#endif // CALC_H
