#ifndef CONTROL_PANEL_H
#define CONTROL_PANEL_H

#include <QMainWindow>
#include "combine.h"

QT_BEGIN_NAMESPACE
namespace Ui { class control_panel; }
QT_END_NAMESPACE

class control_panel : public combine
{
    Q_OBJECT

public:
    control_panel(QWidget *parent = nullptr);
    ~control_panel();

    Ui::control_panel *ui;
private:

};
#endif // CONTROL_PANEL_H
