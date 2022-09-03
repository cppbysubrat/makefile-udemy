#pragma once
#include <string>
#include <list>

#include "employee.h"

class DB_Reader {

	public:
        bool read_emp_data(const std::list<Employee> &emp_list, const std::string& emp_id, Employee &emp);
};
