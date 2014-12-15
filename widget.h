#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QGraphicsView>
#include <QPixmap>
#include <QLabel>
#include <QTextEdit>
#include <QPushButton>
#include <QLineEdit>
#include "bbQueue.h"
#include "customer.h"
#include "teller.h"
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <QTimer>
#include <QLCDNumber>

namespace Ui {
class Widget;
}

class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();

private slots:
    void startClicked();
    void startSim();
    void setGUI();

private:
    Ui::Widget *ui;
    QLineEdit *iobox[10];
    QPushButton *button;
    QLabel *label[10];
    QGraphicsScene *scnHappy;
    QGraphicsScene *scnSad;
    QGraphicsScene *scnIndiff;
    QGraphicsScene *scnTeller;
    QGraphicsScene *scnBlank;
    QGraphicsScene *scnBreak;
    QGraphicsView *fBank[14][10];
    QGraphicsView *sBank[14][10];
    QLCDNumber *clock;
    int cNum, tNum, curTime, totalCustomer, totalCustomerSB, totalWaitTime, totalWaitTimeSB,
        totalCustomerLost, totalCustomerLostSB, numberOfLineJumps, leavingI,
        leavingJ, SBLeavingI, SBLeavingJ, wonOvers;
    teller *fbTeller, *sbTeller;
    bbQueue *fbLine, sbLine;
    customer *endOfTheLine;

    void enterQ(customer c = customer());
    void SBEnterQ(customer c = customer());
    bool shortestLine(int &s);
};

#endif // WIDGET_H
