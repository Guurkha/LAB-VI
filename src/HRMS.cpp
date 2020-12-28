#include "HRMS.hpp"


void HMRS::add(Employee employee, string departmentid, double salary)
{
    //employee.set_department(departmentid);
    static int a = 0;
    string employee_id = employee.return_employee_id(); //zwracamy id pracownika i na jego 
                                                        //i jest to klucz mapy
    if(workers_map.find(employee_id) != workers_map.end() && a != 0)
    {
        throw My_Exception_duplicated_id();
    }
    employee.set_department(departmentid); 
    this->workers_map[employee_id] = employee;
             //dodajemy do mapy pracownikow pracownika
    this->department_map[departmentid].push_back(employee_id); //dodajemy do mapy departamentow departament, klucz to departamentID
                                                                //push back bo wektor
    this->salaries[employee_id] = salary;               //dodajemy do mapy wynagrodzen wynagrodzenie
    
}

void HMRS::print_salary()
{
    cout << "wypisanie wyplat" << endl << endl;

    for (auto& s: this->workers_map) { //auto sam dedukuje typ, mozna napisac map
        Employee e = s.second;  //do second bo pierwsze to klucz drugie to wartosc
        cout << "ID :" << e.return_employee_id() << endl;
        cout << "imie :" << e.return_employee_name() << endl;
        cout << "nazwisko :" << e.return_employee_surname() << endl;
        cout << "stanowisko :" << e.return_employee_position() << endl;
        cout << "departament :" << e.return_employee_department_id() << endl;
        cout << "zarobek :" << salaries[e.return_employee_id()] << endl << endl; //mapa o kluczu zwracanym z funkcji employee id. 
    }
}

void HMRS::printDepartment(string departmentid)
{
    cout << "w departamencie " << departmentid << " pracuja:" << endl << endl;
    if(this->department_map.find(departmentid) == this->department_map.end()) //jesli find dobiegl konca to nic nie znalazł
    {
        cout << departmentid << ": ";
        throw My_Exception_department();
    }
    auto department_wypisz = this->department_map[departmentid]; //stworz zmienna tego typu
    for(auto &s: department_wypisz)
    {
        cout << workers_map[s].return_employee_name() << " " << workers_map[s].return_employee_surname() << endl;
    }

}

void HMRS::changeSalary(string employeeId, double salary)
{
    if (salaries.find(employeeId) == salaries.end())
    {
        throw My_Exception_no_such_id();
    }
    
    salaries[employeeId] = salary;
}

void HMRS::printSalariesSorted()
{
    vector<std::pair<Employee, double>> pair;
    for(auto &s: workers_map)
    {
        Employee a = s.second; 
        pair.push_back(std::make_pair(a,salaries[a.return_employee_id()])); //tak trzeba
    }
    sort(pair.begin(), pair.end(), [=](std::pair<Employee, double>&a, std::pair<Employee, double>&b )
    {
    return a.second > b.second;
    }

    );
    cout << "posortowane wg wynagrodzenia" << endl << endl;
    for (auto& s: pair) { //auto sam dedukuje typ, mozna napisac map
        Employee e = s.first;  //do first bo first to klucz typu employee
        cout << "ID :" << e.return_employee_id() << endl;
        cout << "imie :" << e.return_employee_name() << endl;
        cout << "nazwisko :" << e.return_employee_surname() << endl;
        cout << "stanowisko :" << e.return_employee_position() << endl;
        cout << "departament :" << e.return_employee_department_id() << endl;
        cout << "zarobek :" << salaries[e.return_employee_id()] << endl << endl; //mapa o kluczu zwracanym z funkcji employee id. 
    }
}