#ifndef COMBINE_H
#define COMBINE_H

#include <QMainWindow>
#include "component/frameless/frameless.h"
#include "component/select/select.h"

class control_panel;
class combine : public select
{
public:
    combine(QWidget *parent = nullptr);
    ~combine();
	
public:
    void combine_init(control_panel *control);

private:
    control_panel *main_pointer;
};

#endif // COMBINE_H
