#include <iostream>
#include <string>
using namespace std;

string ReadPersonName();
unsigned short ReadPersonAge();
void ReadPersonSalary(double* salary);

void ReadPersonData(string& name, unsigned short& age, double& salary){
	cout << "Input name: ";
	name = ReadPersonName();
	cout << "Input age: ";
	age = ReadPersonAge();
	cout << "Input salary: ";
	ReadPersonSalary(&salary);
}