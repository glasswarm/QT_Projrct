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

     add_components_init();
     Css_init();
     Size_init();
     group_button_init();
     state_search_init();
     Line_init();


     select_wifi_btn->setChecked(true);
}

void select::add_components_init()
{

     main_pointer->ui->add_components->setIcon(QIcon(QPixmap(":/select/images/Resources/Icon/select/add.png")) );
     main_pointer->ui->add_components->setLayoutDirection(Qt::LayoutDirection::RightToLeft);
     main_pointer->ui->add_components->setIconSize(QSize(25,25));

}

void select::Line_init()
{
     main_pointer->ui->head_line ->setFrameShadow(QFrame::Plain);
     main_pointer->ui->head_line ->setMidLineWidth(1);

     main_pointer->ui->search_line ->setFrameShadow(QFrame::Plain);
     main_pointer->ui->search_line ->setMidLineWidth(1);
}

void select::state_search_init()
{
     main_pointer->ui->state_search->setPlaceholderText("Search in list");
     main_pointer->ui->state_search->setTextMargins(7,0,24+2,3);

     main_pointer->ui->search_Icon->setIcon(QIcon(QPixmap(":/select/images/Resources/Icon/select/search_Icon.png")) );
     main_pointer->ui->search_Icon->setIconSize(QSize(25,25));
     main_pointer->ui->search_Icon->setToolTip(tr("search for state"));

     connect(main_pointer->ui->search_Icon,&QPushButton::clicked ,main_pointer,&select::search_Icon_event  );

//     main_pointer->ui->state_search_Layout->setContentsMargins(30,0,0,0);

}
void select::search_Icon_event()
{

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
         main_pointer->ui->video_btn   ->setStyleSheet(qssStyle);
         main_pointer->ui->setting_btn ->setStyleSheet(qssStyle);
         main_pointer->ui->about_btn   ->setStyleSheet(qssStyle);

         main_pointer->ui->search_Icon ->setStyleSheet(qssStyle);
         main_pointer->ui->head        ->setStyleSheet(qssStyle);
         main_pointer->ui->version     ->setStyleSheet(qssStyle);
         main_pointer->ui->head_Icon   ->setStyleSheet(qssStyle);
         main_pointer->ui->state       ->setStyleSheet(qssStyle);
         main_pointer->ui->state_list  ->setStyleSheet(qssStyle);
         main_pointer->ui->state_list_widget->setStyleSheet(qssStyle);
         main_pointer->ui->add_components   ->setStyleSheet(qssStyle);
         main_pointer->ui->state_search->setStyleSheet(qssStyle);

         main_pointer->ui->serial_light->setStyleSheet(qssStyle);
         main_pointer->ui->wifi_light  ->setStyleSheet(qssStyle);

         main_pointer->ui->head_line   ->setStyleSheet(qssStyle);
         main_pointer->ui->search_line ->setStyleSheet(qssStyle);
         qssFile.close();
     }


     main_pointer->ui->wifi_btn    ->setIcon(QIcon(QPixmap(":/select/images/Resources/Icon/select/Wifi_selected.png")));
     main_pointer->ui->wifi_btn    ->setIconSize(QSize(20,20));
     main_pointer->ui->serial_btn  ->setIcon(QIcon(QPixmap(":/select/images/Resources/Icon/select/serial.png")));
     main_pointer->ui->serial_btn  ->setIconSize(QSize(30,30));
     main_pointer->ui->video_btn   ->setIcon(QIcon(QPixmap(":/select/images/Resources/Icon/select/video.png")));
     main_pointer->ui->video_btn   ->setIconSize(QSize(20,20));
     main_pointer->ui->setting_btn ->setIcon(QIcon(QPixmap(":/select/images/Resources/Icon/select/setting.png")));
     main_pointer->ui->setting_btn ->setIconSize(QSize(20,20));
     main_pointer->ui->about_btn   ->setIcon(QIcon(QPixmap(":/select/images/Resources/Icon/select/about.png")));
     main_pointer->ui->about_btn   ->setIconSize(QSize(20,20));


     select_serial_btn        ->setText(" 串口助手         ");
     select_wifi_btn          ->setText(" 网络助手        ");
     select_video_btn         ->setText(" 视频播放        ");
     select_setting_btn       ->setText(" 设置            ");
     select_about_btn         ->setText(" 软件信息        ");
     main_pointer->ui->head   ->setText("琉璃助手");
     main_pointer->ui->state  ->setText("状态表");
     main_pointer->ui->version->setText("V0.0.4");
     main_pointer->ui->add_components->setText("      ADD COMPONENTS");


     main_pointer->ui->serial_light->setToolTip(tr("太阳佬"));

}

void select::Size_init()
{

     main_pointer->ui->select->setMaximumWidth(230);
     select_wifi_btn         ->setMaximumHeight(32);
     select_serial_btn       ->setMaximumHeight(32);
     select_video_btn        ->setMaximumHeight(32);
     select_setting_btn      ->setMaximumHeight(32);
     select_about_btn       ->setMaximumHeight(32);
     main_pointer->ui->add_components->setMaximumHeight(45);
     main_pointer->ui->add_components->setMaximumWidth(195);

     main_pointer->ui->select->setMinimumWidth(230);
     select_wifi_btn         ->setMinimumHeight(32);
     select_serial_btn       ->setMinimumHeight(32);
     select_video_btn        ->setMinimumHeight(32);
     select_setting_btn      ->setMinimumHeight(32);
     select_about_btn        ->setMinimumHeight(32);

     main_pointer->ui->add_components->setMinimumHeight(42);
     main_pointer->ui->add_components->setMaximumHeight(42);
     main_pointer->ui->add_components->setMinimumWidth(205);
     main_pointer->ui->add_components->setMaximumWidth(205);

     main_pointer->ui->head_Icon ->setMinimumWidth (24);
     main_pointer->ui->head_Icon ->setMinimumHeight(24);
     main_pointer->ui->head_Icon ->setMaximumWidth (24);
     main_pointer->ui->head_Icon ->setMaximumHeight(24);

     main_pointer->ui->state_search->setMinimumHeight(34);
     main_pointer->ui->state_search->setMaximumHeight(34);
     main_pointer->ui->state_search->setMinimumWidth(208);
     main_pointer->ui->state_search->setMaximumWidth(208);
}



void select::group_button_init()
{
     select_group->addButton(select_wifi_btn    ,0);
     select_group->addButton(select_serial_btn  ,1);
     select_group->addButton(select_video_btn   ,2);
     select_group->addButton(select_setting_btn ,3);
     select_group->addButton(select_about_btn   ,4);
     select_group->setExclusive(true);//设置为互斥事件

     select_wifi_btn    ->setCheckable(true);
     select_serial_btn  ->setCheckable(true);
     select_video_btn   ->setCheckable(true);
     select_setting_btn ->setCheckable(true);
     select_about_btn   ->setCheckable(true);
     /* 此处connect为多个同名函数寻找写法
      *
      * static_cast<返回值类型 (类:: *)(参数)>(&QButtonGroup::buttonClicked)    //格式
      *
      */
     //connect(select_group,static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonPressed ),main_pointer, &select::press_trans );
     connect(select_group,static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonReleased ),main_pointer, &select::press_trans );
     connect(select_group,static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonReleased ),main_pointer, &select::select_Icon_switch );

}

void select:: press_trans()
{
    state = select_group->checkedId();
    qDebug()<<"previous "<< state;
/*
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
*/
}



void select::select_Icon_switch()
{
     Btn_clear();
     if     (state == wifi_page  )
     {
         select_wifi_btn ->setIcon(QIcon(QPixmap(":/select/images/Resources/Icon/select/Wifi_selected.png")));
         select_wifi_btn ->setIconSize(QSize(20,20));

     }
     else if(state == serial_page)
     {
         select_serial_btn ->setIcon(QIcon(QPixmap(":/select/images/Resources/Icon/select/serial_selected.png")));
         select_serial_btn ->setIconSize(QSize(30,30));
     }
     else if(state == video_page)
     {
         select_video_btn ->setIcon(QIcon(QPixmap(":/select/images/Resources/Icon/select/video_selected.png")));
         select_video_btn ->setIconSize(QSize(20,20));
     }
     else if(state == setting_page)
     {
         select_setting_btn ->setIcon(QIcon(QPixmap(":/select/images/Resources/Icon/select/setting_selected.png")));
         select_setting_btn ->setIconSize(QSize(20,20));
     }
     else if(state == about_page)
     {
         select_about_btn ->setIcon(QIcon(QPixmap(":/select/images/Resources/Icon/select/about_selected.png")));
         select_about_btn ->setIconSize(QSize(20,20));
     }
     else;
}


void select::Btn_clear()
{
//     select_wifi_btn          -> setChecked(false);
//     select_serial_btn        -> setChecked(false);
//     select_pushButton_3_btn  -> setChecked(false);
//     select_pushButton_4_btn  -> setChecked(false);
//     select_pushButton_5_btn  -> setChecked(false);


     select_serial_btn  ->setIcon(QIcon(QPixmap(":/select/images/Resources/Icon/select/serial.png")));
     select_serial_btn  ->setIconSize(QSize(30,30));
     select_wifi_btn    ->setIcon(QIcon(QPixmap(":/select/images/Resources/Icon/select/wifi.png")));
     select_wifi_btn    ->setIconSize(QSize(20,20));
     select_video_btn   ->setIcon(QIcon(QPixmap(":/select/images/Resources/Icon/select/video.png")));
     select_video_btn   ->setIconSize(QSize(20,20));
     select_setting_btn ->setIcon(QIcon(QPixmap(":/select/images/Resources/Icon/select/setting.png")));
     select_setting_btn ->setIconSize(QSize(20,20));
     select_about_btn   ->setIcon(QIcon(QPixmap(":/select/images/Resources/Icon/select/about.png")));
     select_about_btn   ->setIconSize(QSize(20,20));
}
