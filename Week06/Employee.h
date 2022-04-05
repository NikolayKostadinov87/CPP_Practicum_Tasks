#pragma once
#include<cstring>
class Employee {
private:
	char* name;
	int age;
	double salary;
	void copy(const Employee& other);
	void erase();
public:
	//Canonisation
	Employee();
	Employee(const Employee&);
	Employee& operator=(const Employee&);
	~Employee();
	//Setters
	void setName(const char*);
	void setAge(int);
	void setSalary(double);
	//Getters
	char* getName() const;
	int getAge() const;
	double getSalary() const;
};
