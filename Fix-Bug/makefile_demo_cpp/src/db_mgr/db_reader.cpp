#include <iostream>
#include "db_reader.h"


bool DB_Reader::read_emp_data(const std::list<Employee>& emp_list, const std::string &emp_id, Employee& emp)
{
  std::clog << __PRETTY_FUNCTION__ << " . Employee ID: " << emp_id <<  std::endl;

  bool is_found = false;
  for(auto& itr: emp_list) {
    if(itr.getId() == emp_id) {
      emp = itr;
      is_found = true;
      break;
    }
  }

  return is_found;

}
