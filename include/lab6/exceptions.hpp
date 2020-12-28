#ifndef LAB6X_HPP
#define LAB6X_HPP
#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include "employee.hpp" 
class My_Exception_department : public exception
{
    virtual const char *what() const throw()
    {
        return "there is no employees in such department";
    }
};

class My_Exception_duplicated_id : public exception
{
    virtual const char *what() const throw()
    {
        return "there is already employee with such ID, can't add";
    }
};

class My_Exception_no_such_id : public exception
{
    virtual const char *what() const throw()
    {
        return "there isn't employee with such id, can't change salary";
    }
};
#endif