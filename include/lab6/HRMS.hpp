#ifndef LAB6H_HPP
#define LAB6H_HPP
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include "employee.hpp"

class HMRS
{
    private:
    map<string, Employee> workers_map;
    map<string, vector<string> > department_map; 
    map<string, double> salaries;
    public:
    void add(Employee employee, string departmentid, double salary);
    void print_salary();
    void printDepartment(string departmentid);
    void changeSalary(string employeeId, double salary);
    void printSalariesSorted();

};
#endif