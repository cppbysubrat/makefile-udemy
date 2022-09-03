#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>

class Employee
{
public:
  Employee();
  Employee(std::string p_id,
           std::string p_name,
           std::string p_designation);


  std::string getId() const;
  void setId(const std::string &value);

  std::string getName() const;
  void setName(const std::string &value);

  std::string getDesignation() const;
  void setDesignation(const std::string &value);

private:
  std::string id{};
  std::string name{};
  std::string designation{};

};

#endif // EMPLOYEE_H
