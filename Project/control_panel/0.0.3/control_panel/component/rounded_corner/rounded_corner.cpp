#include "rounded_corner.h"
#include "control_panel.h"
#include "ui_control_panel.h"

rounded_corner::rounded_corner(QWidget *parent) : select(parent)
{

}

rounded_corner::~rounded_corner()
{

}

void rounded_corner::rounded_corner_init(control_panel *control)
{

     main_pointer = control;
     main_pointer->setAttribute(Qt::WA_TranslucentBackground);//设置窗口背景透明
     main_pointer->setWindowFlags(Qt::FramelessWindowHint);   //设置无边框窗口
}

void rounded_corner::paintEvent(QPaintEvent *event)
{
    QPainter painter(main_pointer);
    painter.setRenderHint(QPainter::Antialiasing);  // 反锯齿;
    painter.setBrush(QColor(240,240,240));
    painter.setPen(Qt::transparent);
    QRect rect = main_pointer->rect();
    rect.setWidth(rect.width() - 1);
    rect.setHeight(rect.height() - 1);
    painter.drawRoundedRect(rect, round_degree, round_degree);
    //也可用QPainterPath 绘制代替 painter.drawRoundedRect(rect, 15, 15); { QPainterPath painterPath; painterPath.addRoundedRect(rect, 15, 15); p.drawPath(painterPath); } QWidget::paintEvent(event);
}
