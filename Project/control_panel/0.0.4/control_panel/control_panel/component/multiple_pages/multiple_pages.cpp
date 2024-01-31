#include "multiple_pages.h"
#include "control_panel.h"
#include "ui_control_panel.h"

#include "combine.h"

multiple_pages::multiple_pages(QWidget *parent) : rounded_corner(parent)
{

}

multiple_pages::~multiple_pages()
{

}

void multiple_pages::pages_init(control_panel *control)
{
     main_pointer = control;
     main_pointer->ui->stackedWidget->setCurrentIndex(1);

     Css_init();
     switch_init();
     Line_init();
     size_init();
}

void multiple_pages::Css_init()
{
     QFile qssFile(":/Css/Resources/Css/pages.qss");//注意qss文件的保存路径
     qssFile.open(QFile::ReadOnly);
     if(qssFile.isOpen())
     {
         QString qssStyle = QLatin1String(qssFile.readAll());

         main_pointer->ui->pages_widget->setStyleSheet(qssStyle);
         main_pointer->ui->label->setStyleSheet(qssStyle);
         main_pointer->ui->wifi_line->setStyleSheet(qssStyle);
         main_pointer->ui->frame->setStyleSheet(qssStyle);
         main_pointer->ui->wifi_task->setStyleSheet(qssStyle);
         qssFile.close();
     }
}

void multiple_pages::size_init()
{
    main_pointer->ui->wifi_task->setMinimumWidth(295);
    main_pointer->ui->wifi_task->setMaximumWidth(295);

}
void multiple_pages::Line_init()
{
    main_pointer->ui->wifi_line ->setFrameShadow(QFrame::Plain);
    main_pointer->ui->wifi_line ->setMidLineWidth(1);
}


void multiple_pages::switch_init()
{
     connect(select::select_group,static_cast<void(QButtonGroup::*)(int)>(&QButtonGroup::buttonReleased ),main_pointer, &multiple_pages::pages_switch );
}
void multiple_pages::pages_switch()
{
     if     (state == serial_page )main_pointer->ui->stackedWidget->setCurrentIndex(0);
     else if(state == wifi_page   )main_pointer->ui->stackedWidget->setCurrentIndex(1);
     else;
}

