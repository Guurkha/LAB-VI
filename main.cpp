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