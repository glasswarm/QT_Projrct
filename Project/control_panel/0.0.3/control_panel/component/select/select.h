#ifndef SELECT_H
#define SELECT_H

#include "component/frameless/frameless.h"

#include <QMainWindow>
#include <QButtonGroup>
#include <QDebug>
#include <QFile>

#define select_wifi_btn          main_pointer->ui->wifi_btn
#define select_serial_btn        main_pointer->ui->serial_btn
#define select_pushButton_3_btn  main_pointer->ui->pushButton_3
#define select_pushButton_4_btn  main_pointer->ui->pushButton_4
#define select_pushButton_5_btn  main_pointer->ui->pushButton_5

#define select_font_size 14

enum
{
    wifi_page = 0,
    serial_page,
    btn3_page,
    btn4_page,
    btn5_page,
    none_page
}page;

class control_panel;
class select : public frameless
{
public:
    select(QWidget *parent = nullptr);
    ~select();

public:
    void select_init(control_panel *control);

private:
    void contents_init();
    void Css_init();
    void Size_init();
    void group_button_init();

private:
    void Btn_clear();
    void contents();

public slots:
    void press_trans  ();

private:
    control_panel *main_pointer;
private:
    QButtonGroup *select_group = new QButtonGroup();
    unsigned int state;

};
#endif // SELECT_H
