#include "control_panel.h"
#include "ui_control_panel.h"

control_panel::control_panel(QWidget *parent)
    : combine(parent)
    , ui(new Ui::control_panel)
{
    ui->setupUi(this);
    combine_init(this);
}

control_panel::~control_panel()
{
    delete ui;
}

