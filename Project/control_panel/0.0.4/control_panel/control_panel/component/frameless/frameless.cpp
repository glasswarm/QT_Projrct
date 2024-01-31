#include "frameless.h"
#include "control_panel.h"
#include "ui_control_panel.h"


frameless::frameless(QWidget *parent) : QMainWindow(parent)
{

}

frameless::~frameless()
{
}

void frameless::frameless_init(control_panel *control)
{
     main_pointer = control;
     setWindowFlags(Qt::FramelessWindowHint | Qt::Window | Qt::WindowMinimizeButtonHint);//隐藏边框
     main_pointer->setMaximumSize(QGuiApplication::primaryScreen()->availableGeometry().size());//设置显示不遮挡系统标题栏
     constructor();
}

void frameless::constructor()
{
     initWindow();
     size_init();
     Line_init();
     loadQssFile();
     set_Connect();
}

void frameless::loadQssFile()
{
     QFile file(":/Css/Resources/Css/frameless.qss");
     if(file.open(QIODevice::ReadOnly))
     {
         QTextStream text(&file);
         QString styleSheet=text.readAll();

         main_pointer->setStyleSheet(styleSheet);

         main_pointer->ui->search_title     ->setStyleSheet(styleSheet);
         main_pointer->ui->search_title_Icon->setStyleSheet(styleSheet);
         main_pointer->ui->title_line       ->setStyleSheet(styleSheet);
         file.close();
     }
}

void frameless::initWindow()
{
     isMaxWin=false;
     isPressed=false;
     main_pointer->ui->Close_btn->setObjectName("winBtn");
     main_pointer->ui->Min_btn->setObjectName("winBtn");
     main_pointer->ui->Max_btn->setObjectName("winBtn");

     main_pointer->ui->title_Widget->setObjectName("titleLabel");

     main_pointer->ui->Max_btn->setIcon(QIcon(":/title/images/Resources/Icon/title/maxsize.png"));
     main_pointer->ui->Max_btn->setIconSize(QSize(19,19));
     main_pointer->ui->Min_btn->setIcon(QIcon(":/title/images/Resources/Icon/title/minium.png"));
     main_pointer->ui->Close_btn->setIcon(QIcon(":/title/images/Resources/Icon/title/close.png"));
     main_pointer->ui->top_btn->setIcon(QIcon(":/title/images/Resources/Icon/title/top.png"));
     main_pointer->ui->top_btn->setIconSize(QSize(22,22));
     main_pointer->ui->sun_btn->setIcon(QIcon(":/title/images/Resources/Icon/title/sun.png"));
     main_pointer->ui->sun_btn->setIconSize(QSize(22,22));
     main_pointer->ui->more_setting_btn->setIcon(QIcon(":/title/images/Resources/Icon/title/more_setting.png"));

     main_pointer->setWindowIcon(QIcon(":/app/images/Resources/Icon/app.png"));

     main_pointer->ui->search_title_Icon->setIcon(QIcon(QPixmap(":/title/images/Resources/Icon/title/search_title_Icon.png")));
     main_pointer->ui->search_title_Icon->setIconSize(QSize(20,20));

     main_pointer->ui->search_title->setPlaceholderText("Search in current page");
     main_pointer->ui->search_title->setTextMargins(24,2,15,0);
}
void frameless::size_init()
{
//     main_pointer->ui->title_Widget->setMinimumWidth(40);
//     main_pointer->ui->title_Widget->setMinimumHeight(40);
//     main_pointer->ui->title_Widget->setFixedHeight(81);    //固定标题栏高度
     main_pointer->ui->Close_btn   ->setMinimumHeight(46);
     main_pointer->ui->Max_btn     ->setMinimumHeight(46);
     main_pointer->ui->Min_btn     ->setMinimumHeight(46);
     main_pointer->ui->sun_btn     ->setMinimumHeight(46);
     main_pointer->ui->top_btn     ->setMinimumHeight(46);
     main_pointer->ui->more_setting_btn->setMinimumHeight(46);
     main_pointer->ui->search_title->setMinimumHeight(32);

     main_pointer->ui->Close_btn   ->setMaximumHeight(46);
     main_pointer->ui->Max_btn     ->setMaximumHeight(46);
     main_pointer->ui->Min_btn     ->setMaximumHeight(46);
     main_pointer->ui->sun_btn     ->setMaximumHeight(46);
     main_pointer->ui->top_btn     ->setMaximumHeight(46);
     main_pointer->ui->more_setting_btn->setMaximumHeight(46);
     main_pointer->ui->search_title->setMaximumHeight(32);

     main_pointer->ui->title_Widget->move(0,0);

     main_pointer->ui->Close_btn   ->setMaximumWidth(44);
     main_pointer->ui->Max_btn     ->setMaximumWidth(44);
     main_pointer->ui->Min_btn     ->setMaximumWidth(44);
     main_pointer->ui->sun_btn     ->setMaximumWidth(44);
     main_pointer->ui->top_btn     ->setMaximumWidth(44);
     main_pointer->ui->more_setting_btn->setMaximumWidth(44);
     main_pointer->ui->search_title->setMaximumWidth(180);

     main_pointer->ui->Close_btn   ->setMinimumWidth(44);
     main_pointer->ui->Max_btn     ->setMinimumWidth(44);
     main_pointer->ui->Min_btn     ->setMinimumWidth(44);
     main_pointer->ui->sun_btn     ->setMinimumWidth(44);
     main_pointer->ui->top_btn     ->setMinimumWidth(44);
     main_pointer->ui->more_setting_btn->setMinimumWidth(44);
     main_pointer->ui->search_title->setMinimumWidth(180);


}

void frameless::Line_init()
{
     main_pointer->ui->title_line ->setFrameShadow(QFrame::Plain);
     main_pointer->ui->title_line ->setMidLineWidth(1);

     main_pointer->ui->title_top_line    ->setFrameShadow(QFrame::Plain);
     main_pointer->ui->title_top_line    ->setMidLineWidth(1);
     main_pointer->ui->title_middle_line ->setFrameShadow(QFrame::Plain);
     main_pointer->ui->title_middle_line ->setMidLineWidth(1);
     main_pointer->ui->title_bottom_line ->setFrameShadow(QFrame::Plain);
     main_pointer->ui->title_bottom_line ->setMidLineWidth(1);

}

void frameless::set_Connect()
{
     connect(main_pointer->ui->Min_btn  ,&QPushButton::clicked,this,&frameless::windowMin);
     connect(main_pointer->ui->Max_btn  ,&QPushButton::clicked,this,&frameless::windowMax);
     connect(main_pointer->ui->Close_btn,&QPushButton::clicked,this,&frameless::windowClose);
}

//关闭窗口
void frameless::windowClose()
{
    qApp->exit();
}

//窗口最小化
void frameless::windowMin()
{
    main_pointer->showMinimized();
}
//窗口最大化
void frameless::windowMax()
{
    isMaxWin=!isMaxWin;
    if(isMaxWin)//根据是否最大化窗口,改变对应的图标
    {
        main_pointer->ui->Max_btn->setIcon(QIcon(":/title/images/Resources/Icon/title/normal.png"));
        main_pointer->showMaximized();
//        main_pointer->showFullScreen(); //fixed

    }
    else
    {
        main_pointer->ui->Max_btn->setIcon(QIcon(":/title/images/Resources/Icon/title/maxsize.png"));
        main_pointer->showNormal();
    }


}

void frameless:: mouseDoubleClickEvent(QMouseEvent*event)
{
    Q_UNUSED(event);
    if(main_pointer->ui->title_Widget->underMouse())
    {
//        qDebug()<<"double press\n";
        if (!isMaxWin)
        {
            main_pointer->showMaximized();
            main_pointer->ui->Max_btn->setIcon(QIcon(":/title/images/Resources/Icon/title/normal.png"));
            isMaxWin=true;
        }
        else
        {
            main_pointer->showNormal();
            main_pointer->ui->Max_btn->setIcon(QIcon(":/title/images/Resources/Icon/title/maxsize.png"));
            isMaxWin=false;
        }
    }
}

void frameless::mousePressEvent(QMouseEvent*event)
{
    if(event->button()==Qt::LeftButton && main_pointer->ui->title_Widget->underMouse())
    {
//        qDebug()<<"press\n";
        isPressed=true;
        curPos=event->pos();
    }
}

void frameless::mouseMoveEvent(QMouseEvent*event)
{
    if(isPressed)
    {
        main_pointer->move(event->pos()-curPos+main_pointer->pos());
//        qDebug()<<"move\n";
        if(isMaxWin)
        {
            windowMax();
           // this->showMaximized();
        }
    }
}

//鼠标释放
void frameless::mouseReleaseEvent(QMouseEvent*event)
{
//    qDebug()<<"release\n";
    isPressed=false;
}

//消息处理
bool frameless::nativeEvent(const QByteArray &eventType, void *message, long *result)
{

     int m_nBorder = 8;   //设置一个边界宽度用于判断是否处于边界
     Q_UNUSED(eventType)
     MSG *param = static_cast<MSG *>(message);

     switch (param->message)
     {
         case WM_NCHITTEST:
         {
             int nX = GET_X_LPARAM(param->lParam) - main_pointer->geometry().x();
             int nY = GET_Y_LPARAM(param->lParam) - main_pointer->geometry().y();


             *result = HTCAPTION;

             //判断鼠标位置是否位于窗口边界
             if ((nX > 0) && (nX < m_nBorder))
                 *result = HTLEFT;

             if ((nX > main_pointer->width() - m_nBorder) && (nX < main_pointer->width()))
                 *result = HTRIGHT;

             if ((nY > 0) && (nY < m_nBorder))
                 *result = HTTOP;

             if ((nY > main_pointer->height() - m_nBorder) && (nY < main_pointer->height()))
                 *result = HTBOTTOM;

             if ((nX > 0) && (nX < m_nBorder) && (nY > 0)
                     && (nY < m_nBorder))
                 *result = HTTOPLEFT;

             if ((nX > main_pointer->width() - m_nBorder) && (nX < main_pointer->width())
                     && (nY > 0) && (nY < m_nBorder))
                 *result = HTTOPRIGHT;

             if ((nX > 0) && (nX < m_nBorder)
                     && (nY > main_pointer->height() - m_nBorder) && (nY < main_pointer->height()))
                 *result = HTBOTTOMLEFT;

             if ((nX > main_pointer->width() - m_nBorder) && (nX < main_pointer->width())
                     && (nY > main_pointer->height() - m_nBorder) && (nY < main_pointer->height()))
                 *result = HTBOTTOMRIGHT;

             if (*result == HTCAPTION)
             {
                 return false;
             }
             return true;
         }
     }
     return QMainWindow::nativeEvent(eventType, message, result);
}


