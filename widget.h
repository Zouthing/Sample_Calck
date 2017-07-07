#ifndef WIDGET_H
#define WIDGET_H
#include <QApplication> //  �������� ����������
#include <QPushButton>  //  ���������� ��� �������� � ������ � ��������
#include <QLCDNumber>   //  ���������� ��� �������� � ����������� ��������������������� �������
#include <QtGui>        //  ���������� �������� �����������
#include <QtCore>       //  ����������� ���������� ����
#include <QGridLayout>  //  ���������� �������������� ���������� � ������������� �� �����

#include <QWidget>
#include <QLabel>

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
    void dig_modul(int x);
    void on_pushButton_clicked();
    void on_pushButton_Point_clicked();

    void on_pushButton_oper_clicked();
    void on_pushButton_M_clicked();
    void on_pushButton_C_clicked();
    void on_pushButton_CE_clicked();
    void on_pushButton_BC_clicked();
private:
    Ui::Widget *ui;
        QLCDNumber *lcdNumber = new QLCDNumber;
        QLabel *xylabel = new QLabel;
        double mem_x  = 0.0;
        double disp_x = 0.0;
        double disp_y = 0.0;
        double disp_z = 0.0;
        int reg_x = 0.0; //  ����������� X
        int reg_y = 0.0; //  ����������� X
        int divide_x = 0; //  ��������
        int divide_y = 0; //  ��������
        int kof = 1;    //  ����������� ����������� �����
        int poz_x = 0;      //  ������� �����
        int poz_y = 0;      //  ������� �����
        char funk_xy=0; //  ����������� �������
        QString op = " ";

};


#endif // WIDGET_H
