#include "select.h"
#include "control_panel.h"
#include "ui_control_panel.h"

select::select(QWidget *parent) : frameless(parent)
{

}

select::~select()
{

}

void select::select_init(control_panel *control)
{
     main_pointer = control;
     Css_init();
     Size_init();
     group_button_init();
//     select_wifi_btn->setChecked(true);
     select_wifi_btn->setChecked(true);
}

void select::Css_init()
{
     QFile qssFile(":/Css/Resources/Css/select.qss");//注意qss文件的保存路径
     qssFile.open(QFile::ReadOnly);

     if(qssFile.isOpen())

     {
         QString qssStyle = QLatin1String(qssFile.readAll());

         main_pointer->ui->select      ->setStyleSheet(qssStyle);
         main_pointer->ui->wifi_btn    ->setStyleSheet(qssStyle);
         main_pointer->ui->serial_btn  ->setStyleSheet(qssStyle);
         main_pointer->ui->pushButton_3->setStyleSheet(qssStyle);
         main_pointer->ui->pushButton_4->setStyleSheet(qssStyle);
         main_pointer->ui->pushButton_5->setStyleSheet(qssStyle);

         qssFile.close();
     }
     main_pointer->ui->wifi_btn->setIcon(QIcon(QPixmap(":/image/Resources/Icon/wifi.png")));
     main_pointer->ui->wifi_btn->setIconSize(QSize(20,20));

     select_wifi_btn         ->setFont(QFont("楷体",select_font_size));
     select_serial_btn       ->setFont(QFont("楷体",select_font_size));
     select_pushButton_3_btn ->setFont(QFont("楷体",select_font_size));
     select_pushButton_4_btn ->setFont(QFont("楷体",select_font_size));
     select_pushButton_5_btn ->setFont(QFont("楷体",select_font_size));
}

void select::Size_init()
{

     main_pointer->ui->select->setMaximumWidth(240);
     select_wifi_btn         ->setMaximumHeight(70);
     select_serial_btn       ->setMaximumHeight(70);
     select_pushButton_3_btn ->setMaximumHeight(70);
     select_pushButton_4_btn ->setMaximumHeight(70);
     select_pushButton_5_btn ->setMaximumHeight(70);

     main_pointer->ui->select->setMinimumWidth(240);
     select_wifi_btn         ->setMinimumHeight(70);
     select_serial_btn       ->setMinimumHeight(70);
     select_pushButton_3_btn ->setMinimumHeight(70);
     select_pushButton_4_btn ->setMinimumHeight(70);
     select_pushButton_5_btn ->setMinimumHeight(70);
}

void select::group_button_init()
{
     select_group->addButton(select_wifi_btn        ,0);
     select_group->addButton(select_serial_btn      ,1);
     select_group->addButton(select_pushButton_3_btn,2);
     select_group->addButton(select_pushButton_4_btn,3);
     select_group->addButton(select_pushButton_5_btn,4);
     select_group->setExclusive(true);//设置为互斥事件

     select_wifi_btn        ->setCheckable(true);
     select_serial_btn      ->setCheckable(true);
     select_pushButton_3_btn->setCheckable(true);
     select_pushButton_4_btn->setCheckable(true);
     select_pushButton_5_btn->setCheckable(true);
     /* 此处connect为多个同名函数寻找写法
      *
      * static_cast<返回值类型 (类:: *)(参数)>(&QButtonGroup::buttonClicked    //格式
      *
      */
     connect(select_group,static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonPressed ),main_pointer, &select::press_trans );

}

void select:: press_trans()
{
    state = select_group->checkedId();
    qDebug()<<"previous "<< state;
    if (state != 65535)
    {
        select_group->setExclusive(false); // 先取消互斥
        Btn_clear();
        if     (state == wifi_page  )select_wifi_btn        ->setChecked(true);
        else if(state == serial_page)select_serial_btn      ->setChecked(true);
        else if(state == btn3_page  )select_pushButton_3_btn->setChecked(true);
        else if(state == btn4_page  )select_pushButton_4_btn->setChecked(true);
        else if(state == btn5_page  )select_pushButton_5_btn->setChecked(true);
        select_group->setExclusive(true); // 再设置互斥
    }
    else;
}

void select::Btn_clear()
{
     select_wifi_btn          -> setChecked(false);
     select_serial_btn        -> setChecked(false);
     select_pushButton_3_btn  -> setChecked(false);
     select_pushButton_4_btn  -> setChecked(false);
     select_pushButton_5_btn  -> setChecked(false);
}
