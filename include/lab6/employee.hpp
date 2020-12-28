#ifndef LAB6E_HPP
#define LAB6E_HPP
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>


using namespace std;

class Employee
{
    private:
    string id;
    string name;
    string surname; 
    string department_id; //identyfikator dzialu
    string position; //stanowisko
    public:
    Employee();
    Employee(string, string, string, string);
    string return_employee_id();
    string return_employee_name();
    string return_employee_surname();
    string return_employee_department_id();
    string return_employee_position();
    void introduce_yourself();
    void set_department(string);
};
#endif