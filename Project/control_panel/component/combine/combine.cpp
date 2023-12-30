#include "combine.h"


combine::combine(QWidget *parent) : select(parent)
{
	
}

combine::~combine()
{

}

void combine::combine_init(control_panel *control)
{

     frameless_init(control);
     select_init(control);
}
