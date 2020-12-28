#include "HRMS.hpp"
#include "employee.hpp"
#include"exceptions.hpp



int main()
{
    Employee Jan("1111", "Jan", "Gorka", "junior");
    Employee Maciek("12111", "Kamil", "Plucinski", "senior");
    Employee Maro("0777", "Marek", "Mikolajski", "seniordev");
    Employee Natalka("12321", "Natalka", "Ziobro", "senior");
    Employee Marysia("12451", "Marysia", "Nowak", "seller");
    Employee Karo("12115", "Karolina", "Sarna", "weber");
    Employee Jarek("1912", "Jarek", "Kociarz", "wodz");
    Employee Lukasz("2020", "Lukasz", "Zubek", "rescuer");
    Employee Oliwia("2000", "Oliwia", "Kot", "historian");
    Employee Fernando("342355", "Fernando", "Alvarez", "pro-player");
    //Jan.introduce_yourself();
    HMRS hmrs;
    try
    {
        hmrs.add(Jan, "frontend", 2800);
    // hmrs.add(Jan, "frontend", 2800);
        hmrs.add(Maciek, "frontend", 7800);
        hmrs.add(Natalka, "ddss", 7320);
        hmrs.add(Marysia, "frontend", 120);
        hmrs.add(Karo, "dsds", 20);
        hmrs.add(Maro, "ddss", 80900);
        hmrs.add(Jarek, "depart1", 2900);
        hmrs.add(Maro, "depart2", 5300);
        hmrs.add(Maro, "frontend", 900);
        hmrs.add(Maro, "depart2", 2100);
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }
    hmrs.print_salary();
    try
    {
        //hmrs.printDepartment("sanias");
        hmrs.printDepartment("frontend");
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }
    try
    {
        hmrs.changeSalary("1111", 12);
        hmrs.changeSalary("1", 2222);
    }
    catch(exception &e)
    {
        cout << e.what() << endl;
    }
    
    hmrs.print_salary();
    hmrs.printSalariesSorted();
    return 0;
}