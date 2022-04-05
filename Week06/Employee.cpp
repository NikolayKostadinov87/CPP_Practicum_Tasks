#include "Employee.h"
void Employee::copy(const Employee& other)
{
	if (name != nullptr) erase();
	setName(other.name);
	setAge(other.age);
	setSalary(other.salary);
}

void Employee::erase()
{
	delete[] name;
}

Employee::Employee()
{
	this->name = nullptr;
	age = 0;
	salary = 0.0;
}

Employee::Employee(const Employee& other)
{
	copy(other);
}

Employee& Employee::operator=(const Employee& other)
{
	if (this != &other) {
		erase();
		copy(other);
	}
	return *this;
}

Employee::~Employee()
{
	delete[] name;
}

void Employee::setName(const char* name)
{
	int length = strlen(name);
	if (length == 0) {
		throw "Invalid name ";
	}for (int i = 0; i < length; i++) {
		if ((name[i] < 'a' || name[i] > 'z') && (name[i] < 'A' || name[i] > 'Z') && name[i] != ' ') {
			throw "The name has to contain only letters (a-zA-Z) and whitespace ' '";
		}
	}
	delete[] this->name;
	this->name = new char[strlen(name) + 1];
	strcpy_s(this->name, strlen(name) + 1, name);
}

void Employee::setAge(int age)
{
	if (age < 14 || age > 70) {
		throw "Age has to be between 14 and 70";
	}
	this->age = age;
}

void Employee::setSalary(double salary)
{
	if (salary < 0) {
		throw "Salary has to be positive number!";
	}
	this->salary = salary;
}

char* Employee::getName() const
{
	return name;
}

int Employee::getAge() const
{
	return age;
}

double Employee::getSalary() const
{
	return salary;
}

