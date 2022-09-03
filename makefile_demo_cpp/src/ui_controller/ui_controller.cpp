#include <iostream>

#include "ui_controller.h"

UI_Controller::UI_Controller() {

	std::clog << "UI_CONTROLLER CONSTRUCTOR\n";
}

void UI_Controller::get_emp_id_and_show_details()
{
  std::string id;
    DB_Mgr dbMgrObj;
  do {

    id.erase();
    std::clog << "\nEnter employee ID: ";
    std::getline(std::cin, id);
    auto emp = dbMgrObj.get_emp_details(id);
    std::clog << "ID: " << emp.getId() << "\nName: " << emp.getName() << "\nDesig: " << emp.getDesignation() << std::endl;
  } while(id != "0");
}



void UI_Controller::show() {

	std::clog << __PRETTY_FUNCTION__ << "\n";
    get_emp_id_and_show_details();
}
