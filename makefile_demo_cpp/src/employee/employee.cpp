#include <iostream>
#include "employee.h"

Employee::Employee()
{

}

Employee::Employee(std::string p_id, std::string p_name, std::string p_designation):id(p_id), name(p_name), designation(p_designation)
{
  std::clog << __PRETTY_FUNCTION__ << std::endl;
}

std::string Employee::getId() const
{
  return id;
}

void Employee::setId(const std::string &value)
{
  id = value;
}

std::string Employee::getName() const
{
  return name;
}

void Employee::setName(const std::string &value)
{
  name = value;
}

std::string Employee::getDesignation() const
{
  return designation;
}

void Employee::setDesignation(const std::string &value)
{
  designation = value;
}
