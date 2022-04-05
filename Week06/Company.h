#pragma once
#include <fstream>
#include "Employee.h"

class Company {
private:
	Employee* employees;
	Employee* currentMaxPaidEmployee;
	int size;
	int capacity;
	void copy(const Company&);
	void erase();
public:
	Company();
	Company(const Company&);
	Company& operator=(const Company&);
	~Company();

	//Adding new employees to the list of employees
	void addEmployee(const Employee&);
	//The most paid employee in the company
	const Employee& getTheMostPaid() const;
	//Save employees in a text file
	void saveEmployees(const char*);
};
