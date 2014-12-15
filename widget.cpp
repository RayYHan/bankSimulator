#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromStdString("Bank Simulator"));
    QPixmap dollar("img/dollar.png");
    setWindowIcon(dollar);
    resize(1000, 820);
    setMaximumSize(865, 820);
    setMinimumSize(865, 820);

    iobox[0] = new QLineEdit(this);
    iobox[0]->setGeometry(QRect(130,20,280,30));
    iobox[0]->setPlaceholderText(QString::fromStdString("Number of tellers (2-10)"));
    iobox[1] = new QLineEdit(this);
    iobox[1]->setGeometry(QRect(450,20,280,30));
    iobox[1]->setPlaceholderText(QString::fromStdString("Number of customers per line (2-10)"));

    button = new QPushButton(this);
    button->setGeometry(QRect(740,20,100,30));
    button->setText(QString::fromStdString("Start"));

    label[0] = new QLabel(this);
    label[0]->setGeometry(QRect(20,60,100,30));
    label[0]->setText(QString::fromStdString("First bank"));
    label[0]->setStyleSheet("QLabel {font-size: 12pt;}");
    label[1] = new QLabel(this);
    label[1]->setGeometry(QRect(450,60,100,30));
    label[1]->setText(QString::fromStdString("Second bank"));
    label[1]->setStyleSheet("QLabel {font-size: 12pt;}");
    label[2] = new QLabel(this);
    label[2]->setGeometry(QRect(20,660,200,30));
    label[2]->setText(QString::fromStdString("Average wait time: "));
    label[3] = new QLabel(this);
    label[3]->setGeometry(QRect(20,700,200,30));
    label[3]->setText(QString::fromStdString("Number of customer helped: "));
    label[4] = new QLabel(this);
    label[4]->setGeometry(QRect(20,740,200,30));
    label[4]->setText(QString::fromStdString("Number of line jumps: "));
    label[5] = new QLabel(this);
    label[5]->setGeometry(QRect(20,780,200,30));
    label[5]->setText(QString::fromStdString("Customers lost: "));
    iobox[2] = new QLineEdit(this);
    iobox[2]->setGeometry(QRect(225,660,190,30));
    iobox[2]->setReadOnly(true);
    iobox[3] = new QLineEdit(this);
    iobox[3]->setGeometry(QRect(225,700,190,30));
    iobox[3]->setReadOnly(true);
    iobox[4] = new QLineEdit(this);
    iobox[4]->setGeometry(QRect(225,740,190,30));
    iobox[4]->setReadOnly(true);
    iobox[5] = new QLineEdit(this);
    iobox[5]->setGeometry(QRect(225,780,190,30));
    iobox[5]->setReadOnly(true);

    label[6] = new QLabel(this);
    label[6]->setGeometry(QRect(450,660,200,30));
    label[6]->setText(QString::fromStdString("Average wait time: "));
    label[7] = new QLabel(this);
    label[7]->setGeometry(QRect(450,700,200,30));
    label[7]->setText(QString::fromStdString("Number of customer helped: "));
    label[8] = new QLabel(this);
    label[8]->setGeometry(QRect(450,740,200,30));
    label[8]->setText(QString::fromStdString("Number customers won over: "));
    label[9] = new QLabel(this);
    label[9]->setGeometry(QRect(450,780,200,30));
    label[9]->setText(QString::fromStdString("Customers lost: "));
    iobox[6] = new QLineEdit(this);
    iobox[6]->setGeometry(QRect(655,660,190,30));
    iobox[6]->setReadOnly(true);
    iobox[7] = new QLineEdit(this);
    iobox[7]->setGeometry(QRect(655,700,190,30));
    iobox[7]->setReadOnly(true);
    iobox[8] = new QLineEdit(this);
    iobox[8]->setGeometry(QRect(655,740,190,30));
    iobox[8]->setReadOnly(true);
    iobox[9] = new QLineEdit(this);
    iobox[9]->setGeometry(QRect(655,780,190,30));
    iobox[9]->setReadOnly(true);

    QPixmap happy("img/happy.png");
    QPixmap sad("img/sadpanda.png");
    QPixmap indiff("img/indifferent.png");
    QPixmap teller("img/teller.png");
    QPixmap blank("img/blank.png");
    QPixmap onBreak("img/onBreak.png");

    scnHappy = new QGraphicsScene();
    scnSad = new QGraphicsScene();
    scnIndiff = new QGraphicsScene();
    scnTeller = new QGraphicsScene();
    scnBlank = new QGraphicsScene();
    scnBreak = new QGraphicsScene();
    scnHappy->setSceneRect(QRect(0,0,30,30));
    scnSad->setSceneRect(QRect(0,0,30,30));
    scnIndiff->setSceneRect(QRect(0,0,30,30));
    scnTeller->setSceneRect(QRect(0,0,30,30));
    scnBlank->setSceneRect(QRect(0,0,30,30));
    scnBreak->setSceneRect(QRect(0,0,30,30));
    scnHappy->addPixmap(happy);
    scnSad->addPixmap(sad);
    scnIndiff->addPixmap(indiff);
    scnTeller->addPixmap(teller);
    scnBlank->addPixmap(blank);
    scnBreak->addPixmap(onBreak);
    clock = new QLCDNumber(this);
    clock->setGeometry(QRect(20,20,100,30));
    clock->display(QString::fromStdString("00:00"));

    for(int i = 0; i < 14; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            fBank[i][j] = new QGraphicsView(this);
            fBank[i][j]->setGeometry(QRect(20+j*40,100+i*40,30,30));
            fBank[i][j]->setStyleSheet("QGraphicsView { border-style: none;background-color:rgb(242, 241, 240); }");
            fBank[i][j]->setScene(scnBreak);
        }
    }
    for(int i = 0; i < 14; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            sBank[i][j] = new QGraphicsView(this);
            sBank[i][j]->setGeometry(QRect(450+j*40,100+i*40,30,30));
            sBank[i][j]->setStyleSheet("QGraphicsView { border-style: none;background-color:rgb(242, 241, 240); }");
            sBank[i][j]->setScene(scnSad);
        }
    }
    connect(iobox[1], SIGNAL(returnPressed()), this, SLOT(startClicked()));
    connect(button, SIGNAL(clicked()), this, SLOT(startClicked()));
}

Widget::~Widget()
{
    delete ui;
}

void Widget::startClicked()
{
    totalCustomer = 0;
    totalWaitTime = 0;
    totalCustomerLost = 0;
    totalCustomerSB = 0;
    totalWaitTimeSB = 0;
    totalCustomerLostSB = 0;
    numberOfLineJumps = 0;
    wonOvers = 0;
    tNum = iobox[0]->text().toInt();
    cNum = iobox[1]->text().toInt();
    for(int i = 0; i < 14; i++)
    {
        for(int j = 0; j < 10; j++)
        {
            fBank[i][j]->setScene(scnBlank);
            sBank[i][j]->setScene(scnBlank);
        }
    }
    if((tNum < 2 || tNum > 10) && (cNum < 2 || cNum > 10))
    {
        iobox[0]->clear();
        iobox[1]->clear();
        iobox[0]->setPlaceholderText(QString::fromStdString("Invalid input, number of tellers (2-10)"));
        iobox[1]->setPlaceholderText(QString::fromStdString("Invalid input, number of customers per line (2-10)"));
    }
    else if(tNum < 2 || tNum > 10)
    {
        iobox[0]->setPlaceholderText(QString::fromStdString("Invalid input, number of tellers (2-10)"));
        iobox[0]->clear();
    }
    else if(cNum < 2 || cNum > 10)
    {
        iobox[1]->setPlaceholderText(QString::fromStdString("Invalid input, number of customers per line (2-10)"));
        iobox[1]->clear();
    }
    else
    {
        curTime = 0;
        srand(time(NULL));
        int t1[tNum], t2[tNum], l[tNum];
        for(int i = 0; i < tNum; i++)
        {
            t1[i] = 0;
            t2[i] = 0;
            l[i] = 0;
        }
        while(*max_element(t1, t1 + tNum) - *min_element(t1, t1 + tNum) < 15 ||
              *max_element(t2, t2 + tNum) - *min_element(t2, t2 + tNum) < 15 ||
              *max_element(l, l + tNum) - *min_element(l, l + tNum) < 30)
        {
            for(int i = 0; i < tNum; i++)
            {
                t1[i] = rand()%180 + 1;
                t2[i] = rand()%180 + 301;
                l[i]  = rand()%120 + 181;
            }
        }
        fbTeller = new teller[tNum];
        sbTeller = new teller[tNum];
        fbLine = new bbQueue[tNum];
        sbLine = bbQueue(cNum * tNum);
        endOfTheLine = new customer[tNum];
        for(int i = 0; i < tNum; i++)
        {
            fbLine[i] = bbQueue(cNum + 1);
            fbTeller[i] = teller(l[i], t1[i], t2[i]);
            sbTeller[i] = teller(l[i], t1[i], t2[i]);
            sbTeller[i].vacate();
        }
        startSim();
    }
}

void Widget::startSim()
{
    QString hr = QString::number(curTime/60+9);
    QString mn = QString::number(curTime%60);
    QString ti = hr + QString::fromStdString(":") + mn;
    clock->display(ti);
    srand(time(NULL));
    int sl = 0;
    if(curTime == 480)
    {
        iobox[2]->setText(QString::number(totalWaitTime/totalCustomer));
        iobox[6]->setText(QString::number(totalWaitTimeSB/totalCustomerSB));
        iobox[3]->setText(QString::number(totalCustomer));
        iobox[7]->setText(QString::number(totalCustomerSB));
        iobox[5]->setText(QString::number(totalCustomerLost));
        iobox[9]->setText(QString::number(totalCustomerLostSB));
        iobox[4]->setText(QString::number(numberOfLineJumps));
        iobox[8]->setText(QString::number(wonOvers));
        return;
    }
    for(int i = 0; i < tNum; i++)
    {
        if(!fbLine[i].empty() && fbLine[i].wellDone())
        {
            totalWaitTime += fbLine[i].pop().waitTime();
            totalCustomer ++;
        }
        if(sbTeller[i].occupied() && endOfTheLine[i].difficulty() == 0)
        {
            totalCustomerSB++;
            totalWaitTimeSB += endOfTheLine[i].waitTime();
            if(!sbLine.empty())
                endOfTheLine[i] = sbLine.pop();
            else
                sbTeller[i].vacate();
        }
        if(!fbTeller[i].onDuty(curTime) && !fbLine[i].empty())
            while(!fbLine[i].empty())
                enterQ(fbLine[i].pop());
        if(!sbTeller[i].onDuty(curTime) && sbTeller[i].occupied())
        {
            if(sbLine.full())
                totalCustomerLostSB++;
            sbLine.returnToTheLine(endOfTheLine[i]);
            sbTeller[i].vacate();
        }
        if(!fbLine[i].empty())
            fbLine[i].moreTime();
        if(shortestLine(sl) && fbLine[i].size() - fbLine[sl].size() > 1)
        {
            fbLine[sl].push(fbLine[i].rPop());
            numberOfLineJumps++;
        }
        if(sbTeller[i].onDuty(curTime) && !sbTeller[i].occupied() && !sbLine.empty())
        {
            endOfTheLine[i] = sbLine.pop();
            sbTeller[i].occupy();
        }
        if(sbTeller[i].occupied())
            endOfTheLine[i].beingServed();
    }
    if(!sbLine.empty())
        sbLine.sbMoreTime();
    if(rand()%2 == 1)
    {
        enterQ();
        SBEnterQ();
    }
    curTime++;
    setGUI();
    QTimer::singleShot(100, this, SLOT(startSim()));
}

void Widget::enterQ(customer c)
{
    int sl = 0;
    if(shortestLine(sl))
    {
        fbLine[sl].push(c);
    }
    else
    {
        totalCustomerLost++;
        if(!c.loyalty() && !sbLine.full())
        {
            SBEnterQ(c);
            wonOvers++;
        }
    }
}

void Widget::SBEnterQ(customer c)
{
    if(!sbLine.full())
    {
        sbLine.push(c);
    }
    else
    {
        totalCustomerLostSB++;
        if(!c.loyalty() && !fbLine->full())
            enterQ(c);
    }
}

bool Widget::shortestLine(int &s)
{
    bool bankFull = true;
    for(int i = 0; i < tNum; i++)
    {
        if(!fbLine[i].full() && fbTeller[i].onDuty(curTime))
            bankFull = false;
        if(fbLine[s].full() || !fbTeller[s].onDuty(curTime))
            s = i;
        else if(fbLine[s].size() > fbLine[i].size() &&
                !fbLine[i].full() &&
                fbTeller[i].onDuty(curTime))
            s = i;
    }
    return !bankFull;
}

void Widget::setGUI()
{
    for(int i = 0; i < tNum; i++)
    {
        if(fbTeller[i].onDuty(curTime))
            fBank[0][i]->setScene(scnTeller);
        else
            fBank[0][i]->setScene(scnBreak);
        if(fbLine[i].empty())
            for(int j = 1; j < 14; j++)
                fBank[j][i]->setScene(scnBlank);
        else
        {
            fBank[1][i]->setScene(scnHappy);
            for(int j = 3; j < fbLine[i].size() + 2; j++)
                fBank[j][i]->setScene(scnIndiff);
            for(int j = fbLine[i].size()+2; j < 14; j++)
                fBank[j][i]->setScene(scnBlank);
        }
        if(sbTeller[i].onDuty(curTime))
            sBank[0][i]->setScene(scnTeller);
        else
            sBank[0][i]->setScene(scnBreak);
        if(sbTeller[i].occupied())
            sBank[1][i]->setScene(scnHappy);
        else
            sBank[1][i]->setScene(scnBlank);
    }
    for(int i = 0; i < sbLine.size(); i++)
        sBank[i/10+3][i%10]->setScene(scnIndiff);
    for(int i = sbLine.size(); i < 100; i++)
        sBank[i/10+3][i%10]->setScene(scnBlank);
}
