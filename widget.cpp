#include "widget.h"
#include "ui_widget.h"


Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget){
    ui->setupUi(this);
    this->setWindowTitle("Calculator");

    QPushButton *button0 = new QPushButton("0");
    QPushButton *button1 = new QPushButton("1");
    QPushButton *button2 = new QPushButton("2");
    QPushButton *button3 = new QPushButton("3");
    QPushButton *button4 = new QPushButton("4");
    QPushButton *button5 = new QPushButton("5");
    QPushButton *button6 = new QPushButton("6");
    QPushButton *button7 = new QPushButton("7");
    QPushButton *button8 = new QPushButton("8");
    QPushButton *button9 = new QPushButton("9");
    QPushButton *buttonAdd = new QPushButton("+");
    QPushButton *buttonSub = new QPushButton("-");
    QPushButton *buttonMul = new QPushButton("*");
    QPushButton *buttonDiv = new QPushButton("/");
    QPushButton *buttonEqui = new QPushButton("=");
    QPushButton *buttonP = new QPushButton(".");
    QPushButton *buttonClear = new QPushButton("CL");
    QPushButton *buttonCL = new QPushButton("CE");
    QPushButton *buttonBS = new QPushButton("BS");
    QPushButton *buttonMP = new QPushButton("M+");
    QPushButton *buttonMM = new QPushButton("M-");
    QPushButton *buttonMC = new QPushButton("MC");
    QPushButton *buttonMR = new QPushButton("MR");
    QGridLayout *layoutc =  new QGridLayout;

    lcdNumber->setDigitCount(10);
    layoutc->addWidget(lcdNumber,  0,   0,  1, 4);
    layoutc->addWidget(xylabel,    1,   0,  1, 4, Qt::AlignCenter);
    layoutc->addWidget(buttonCL,   1+1, 1);
    layoutc->addWidget(buttonClear,1+1, 2);
    layoutc->addWidget(buttonBS,   1+1, 3);
    layoutc->addWidget(button0,    2+1, 0);
    layoutc->addWidget(button1,    2+1, 1);
    layoutc->addWidget(button2,    2+1, 2);
    layoutc->addWidget(buttonAdd,  2+1, 3);
    layoutc->addWidget(button3,    3+1, 0);
    layoutc->addWidget(button4,    3+1, 1);
    layoutc->addWidget(button5,    3+1, 2);
    layoutc->addWidget(buttonSub,  3+1, 3);
    layoutc->addWidget(button6,    4+1, 0);
    layoutc->addWidget(button7,    4+1, 1);
    layoutc->addWidget(button8,    4+1, 2);
    layoutc->addWidget(buttonMul,  4+1, 3);
    layoutc->addWidget(button9,    5+1, 0);
    layoutc->addWidget(buttonP,    5+1, 1);
    layoutc->addWidget(buttonEqui, 5+1, 2);
    layoutc->addWidget(buttonDiv,  5+1, 3);
    layoutc->addWidget(buttonMP,   6+1, 0);
    layoutc->addWidget(buttonMM,   6+1, 1);
    layoutc->addWidget(buttonMC,   6+1, 2);
    layoutc->addWidget(buttonMR,   6+1, 3);
    setLayout(layoutc);
    layoutc->setRowStretch(0,1);

    xylabel->setText("M:" + QString::number(mem_x) + "  Calck " + QString::number(disp_x) + " " + op);
    lcdNumber->display(disp_x);

    connect(button0,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(button1,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(button2,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(button3,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(button4,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(button5,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(button6,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(button7,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(button8,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(button9,SIGNAL(clicked()),this,SLOT(on_pushButton_clicked()));
    connect(buttonP,SIGNAL(clicked()),this,SLOT(on_pushButton_Point_clicked()));
    connect(buttonAdd,SIGNAL(clicked()),this,SLOT(on_pushButton_oper_clicked()));
    connect(buttonSub,SIGNAL(clicked()),this,SLOT(on_pushButton_oper_clicked()));
    connect(buttonMul,SIGNAL(clicked()),this,SLOT(on_pushButton_oper_clicked()));
    connect(buttonDiv,SIGNAL(clicked()),this,SLOT(on_pushButton_oper_clicked()));
    connect(buttonEqui,SIGNAL(clicked()),this,SLOT(on_pushButton_oper_clicked()));
    connect(buttonBS,SIGNAL(clicked()),this,SLOT(on_pushButton_BC_clicked()));
    connect(buttonClear,SIGNAL(clicked()),this,SLOT(on_pushButton_CE_clicked()));
    connect(buttonCL,SIGNAL(clicked()),this,SLOT(on_pushButton_C_clicked()));
    connect(buttonMP,SIGNAL(clicked()),this,SLOT(on_pushButton_M_clicked()));
    connect(buttonMM,SIGNAL(clicked()),this,SLOT(on_pushButton_M_clicked()));
    connect(buttonMC,SIGNAL(clicked()),this,SLOT(on_pushButton_M_clicked()));
    connect(buttonMR,SIGNAL(clicked()),this,SLOT(on_pushButton_M_clicked()));
}

Widget::~Widget() {
    delete ui;
}

void Widget::dig_modul(int x) {
    qreal step = 0.0;
    int powd = 0;
    if((x == 0) && (reg_x == 0)) {  reg_x =   0;  poz_x = 0;
    } else
    if((x != 0) && (reg_x == 0)) {  reg_x =   x;  poz_x = 0;
    } else {        reg_x *= 10;    reg_x +=  x;  poz_x++;
    }
    if(divide_x != 0)     powd = divide_x - poz_x - 1;
    step = qPow ( 10.0, powd);
    disp_x = reg_x * step;
    lcdNumber->display(disp_x);
}

void Widget::on_pushButton_clicked() {
     QPushButton *button = (QPushButton *)sender();
     QString s = button->text();
    int x = s.toInt(0,16);
    dig_modul(x);
}

void Widget::on_pushButton_Point_clicked() {
    if(divide_x == 0)
       divide_x = poz_x + 1;
}
void Widget::on_pushButton_oper_clicked(){
    QPushButton *button = (QPushButton *)sender();
    QString ss = button->text();
    QString ls = "";
    if(ss == "="){
        if(op == "+")
            disp_z = disp_y + disp_x;
        else
        if(op == "-")
            disp_z = disp_y - disp_x;
        else
        if(op == "*")
            disp_z = disp_y * disp_x;
        else
        if(op == "/")
            disp_z = disp_y / disp_x;
        ls = "M:" + QString::number(mem_x) + "  Calck " + QString::number(disp_y) + " " + op + " " + QString::number(disp_x) + " = " + QString::number(disp_z);
        disp_x = disp_z;
        disp_y = 0;
        poz_x = 0;
        xylabel->setText(ls);
        op = " ";
    } else {
        op = ss;
        disp_y = disp_x;
        divide_x = 0;
    }
    lcdNumber->display(disp_x);
    divide_x = 0;
    reg_y = reg_x;
    funk_xy=1;
    reg_x = 0;
    poz_x = 0;
}

void Widget::on_pushButton_C_clicked(){
    reg_x = 0; reg_y = 0; poz_x = 0; funk_xy = 0; divide_x = 0;
    lcdNumber->display(reg_x);
}

void Widget::on_pushButton_CE_clicked(){
    reg_x = 0; poz_x = 0; divide_x = 0;
    lcdNumber->display(disp_y);
}

void Widget::on_pushButton_BC_clicked(){
    int powd = 0;
    if(poz_x > 0){
        poz_x--;
        reg_x = reg_x / 10;
        if(divide_x > 0) divide_x--;
    }
    lcdNumber->display(reg_x);
    if(divide_x != 0)     powd = divide_x - poz_x - 1;
    disp_x = reg_x * qPow ( 10.0, powd);
    lcdNumber->display(disp_x);
    xylabel->setText("M:" + QString::number(mem_x) + "  Calck " + QString::number(disp_y) + " " + op + " " + QString::number(disp_x));
}

void Widget::on_pushButton_M_clicked(){
    QPushButton *button = (QPushButton *)sender();
    QString ss = button->text();

    if(ss == "MR") disp_x = mem_x;
    if(ss == "MC") mem_x = 0.0;
    if(ss == "M+") mem_x += disp_x;
    if(ss == "M-") mem_x -= disp_x;
    xylabel->setText("M:" + QString::number(mem_x) + "  Calck " + QString::number(disp_y) + " " + op + " " + QString::number(disp_x));
    lcdNumber->display(disp_x);
    reg_x = 0; reg_y = 0; poz_x = 0; funk_xy = 0; divide_x = 0;
}
