#ifndef SELECT_H
#define SELECT_H

#include "component/frameless/frameless.h"

#include <QMainWindow>
#include <QButtonGroup>
#include <QDebug>
#include <QFile>

#define select_wifi_btn    main_pointer->ui->wifi_btn
#define select_serial_btn  main_pointer->ui->serial_btn
#define select_video_btn   main_pointer->ui->video_btn
#define select_setting_btn main_pointer->ui->setting_btn
#define select_about_btn   main_pointer->ui->about_btn

#define select_font_size 14

enum
{
    wifi_page = 0,
    serial_page,
    video_page,
    setting_page,
    about_page,
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
    void add_components_init();
    void Css_init();
    void Size_init();
    void group_button_init();

    void Line_init();
    void state_search_init();

public slots:
    void search_Icon_event();
    void select_Icon_switch();
private:
    void Btn_clear();

public slots:
    void press_trans ();

private:
    control_panel *main_pointer;

public:
    QButtonGroup *select_group = new QButtonGroup();
    unsigned int state;

};
#endif // SELECT_H
