#ifndef WIDGET_H
#define WIDGET_H
#include <QApplication> //  Основная библиотека
#include <QPushButton>  //  Библиотека для создания и работы с кнопками
#include <QLCDNumber>   //  Библиотека для создания и отображения жидкокристаллического дисплея
#include <QtGui>        //  Библиотека основных интерфейсов
#include <QtCore>       //  Стандартные библиотеки ядра
#include <QGridLayout>  //  Библиотеак форматирования интерфейса с выравниванием по сетке

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
        int reg_x = 0.0; //  аккумулятор X
        int reg_y = 0.0; //  аккумулятор X
        int divide_x = 0; //  делитель
        int divide_y = 0; //  делитель
        int kof = 1;    //  коэффициент отображения точки
        int poz_x = 0;      //  позиция точки
        int poz_y = 0;      //  позиция точки
        char funk_xy=0; //  применяемая функция
        QString op = " ";

};


#endif // WIDGET_H
