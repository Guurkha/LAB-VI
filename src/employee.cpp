#include "../include/lab6/exceptions.hpp"
#include "../include/lab6/employee.hpp"
#include "../include/lab6/HRMS.hpp"
Employee::Employee()
{

}

Employee::Employee(string id, string name, string surname, string position)
{
    this->id = id;
    this->name = name;
    this->surname = surname;
    this->department_id = department_id;
    this->position = position;
}
string Employee::return_employee_department_id()
{
    return this->department_id;
}
string Employee::return_employee_id()
{
    return this->id;
}
string Employee::return_employee_name()
{
    return this->name;
}
string Employee::return_employee_surname()
{
    return this->surname;
}
string Employee::return_employee_position()
{
    return this->position;
}

void Employee::introduce_yourself()
{
    cout << this->id << endl;
    cout << this->name << endl;
    cout << this->surname << endl;
    cout << this->department_id << endl;
    cout << this->position << endl;

}

void Employee::set_department(string departementID)
{
    this->department_id = departementID;
}