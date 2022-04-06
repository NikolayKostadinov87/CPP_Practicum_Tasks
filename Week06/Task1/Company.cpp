#include"Company.h"

void Company::copy(const Company& other)
{
	capacity = other.capacity;
	size = other.size;
	employees = new Employee[capacity];
	for (int i = 0; i < size; i++) {
		employees[i] = other.employees[i];
	}
}

void Company::erase()
{
	delete[] employees;
}

Company::Company()
{
	capacity = 20;
	size = 0; 
	employees = new Employee[capacity];
}

Company::Company(const Company& other)
{
	copy(other);
}

Company& Company::operator=(const Company& other)
{
	if (this == &other) {
		erase();
		copy(other);
	}
	return *this;
}

Company::~Company()
{
	delete[] employees;
}


void Company::addEmployee(const Employee& newEmployee)
{
	if (size >= capacity) throw "Space needed for more employees!";
	employees[size++] = newEmployee;
}

const Employee& Company::getTheMostPaid() const
{
	int counter = 0 , counter_of_same_payment = 0;
	for (int i = 1; i < size; i++) {
		if (employees[counter].getSalary() < employees[i].getSalary()) {
			counter = i;
		}
	}
	return employees[counter];
}

void Company::saveEmployees(const char* fileName)
{
	std::ofstream ofs;
	ofs.open(fileName);
	if (!ofs) {
		throw "File not opened properly";
	}
	ofs << capacity << std::endl;
	ofs << size << std::endl;
	for (int i = 0; i < size; i++) {
		ofs << "Name -> " << employees[i].getName() << ", Salary -> " << employees[i].getSalary() << " , Age -> " << employees[i].getAge() << std::endl;
	}
}
