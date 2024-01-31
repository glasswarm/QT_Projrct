#ifndef ROUNDED_CORNER_H
#define ROUNDED_CORNER_H

#include "component/select/select.h"

#include <qpainter.h>

#define round_degree 2

class control_panel;
class rounded_corner : public select
{
    Q_OBJECT

public:
    rounded_corner(QWidget *parent = nullptr);
    ~rounded_corner();

public:
    void rounded_corner_init(control_panel *control);

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    control_panel *main_pointer;

};
#endif // ROUNDED_CORNER_H
