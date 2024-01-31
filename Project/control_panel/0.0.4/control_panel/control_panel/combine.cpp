#include "combine.h"


combine::combine(QWidget *parent) : multiple_pages(parent)
{
	
}

combine::~combine()
{

}

void combine::combine_init(control_panel *control)
{
     frameless_init(control);
     select_init(control);
     rounded_corner_init(control);
     pages_init(control);
}
