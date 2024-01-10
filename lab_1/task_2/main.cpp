#include <iostream>
#include <string>
using namespace std;

extern string salaryG;
extern unsigned short height;

void ReadPersonData(string& name, unsigned short& age, double& salary);
void ReadPersonData(string& name, unsigned short& age, unsigned short& height, unsigned short& weight);
void WritePersonData(const string& name, const string& height, const string& weight, const unsigned short* age);

int main(int argc, char** argv)
{
	unsigned short weight, age;
	string name;
	double salary;

	ReadPersonData(name, age, salary);
	salaryG = to_string(salary);
	WritePersonData(name, "", "", &age);
	ReadPersonData(name, age, height, weight);
	WritePersonData(name, to_string(height), to_string(weight), &age);

	return 0;
}

