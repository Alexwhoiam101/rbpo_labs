#include <iostream>
#include <string>
using namespace std;

string salaryG;

void WritePersonData(const string& name, const string& height = "", const string& weight = "", const unsigned short* age = 0){
	cout << "------------------------------" << endl;
	cout << "Name: " << name << endl;
	cout << "Height: " << height << endl;
	cout << "Weight: " << weight << endl;
	cout << "Age: " << *(age) << endl;
	cout << "Salary: " << salaryG << endl;
	cout << "------------------------------" << endl;
}