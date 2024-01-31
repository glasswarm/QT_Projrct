#ifndef MULTIPLE_PAGE_H
#define MULTIPLE_PAGE_H

#include <QMainWindow>

#include "component/rounded_corner/rounded_corner.h"

class control_panel;
class multiple_pages : public rounded_corner
{
public:
    multiple_pages(QWidget *parent = nullptr);
    ~multiple_pages();

public:
    void pages_init(control_panel *control);

private:
    void Css_init();
    void switch_init();
    void Line_init();
    void size_init();
    void pages_switch();
private:
    control_panel *main_pointer;
};

#endif // COMBINE_H
