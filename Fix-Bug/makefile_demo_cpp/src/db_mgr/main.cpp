#include <iostream>

#include "db_mgr.h"
#include "employee.h"

int main() {

    DB_Mgr dbMgrObj;
    std::string id;

    do {
      std::clog << "Enter employee ID: ";
      std::getline(std::cin, id);
      auto emp = dbMgrObj.get_emp_details(id);
      std::clog << "ID: " << emp.getId() << "\nName: " << emp.getName() << "\nDesig: " << emp.getDesignation() << std::endl;
      id.erase();

    } while(id != "0");

    return 0;
}
