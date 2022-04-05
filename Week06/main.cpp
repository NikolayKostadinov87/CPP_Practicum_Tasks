#include <iostream>
#include"Company.h"
int main()
{
	Employee firstEmployee;
	Employee secondEmployee;
	try {
		firstEmployee.setAge(20);
		firstEmployee.setName("Nikolay Kostadinov");
		firstEmployee.setSalary(5500);

	}
	catch (const char* message) {
		std::cout << message << std::endl;
	}
	try {
		secondEmployee.setAge(20);
		secondEmployee.setName("Emil Tsanev");
		secondEmployee.setSalary(5500);
	}
	catch (const char* message) {
		std::cout << message << std::endl;
	}
	Company company;
	try {
		company.addEmployee(firstEmployee);
		company.addEmployee(secondEmployee);
	}
	catch (const char* message) {
		std::cout << message << std::endl;
	}
	//Get the most paid employee
	std::cout << "Most paid employee is : " << company.getTheMostPaid().getName() << std::endl;
	try {
		company.saveEmployees("company.txt");
	}
	catch (const char* message) {
		std::cout << message << std::endl;
	}
	return 0;
}
