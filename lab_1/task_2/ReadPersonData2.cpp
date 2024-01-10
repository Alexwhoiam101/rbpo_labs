#include <string>
using namespace std;

extern unsigned short height;

string ReadPersonName();
unsigned short ReadPersonAge();
void ReadPersonHeight();
void ReadPersonWeight(unsigned short& weight);

void ReadPersonData(string& name, unsigned short& age, unsigned short& height, unsigned short& weight) {
	cout << "Input name: ";
	name = ReadPersonName();
	cout << "Input age: ";
	age = ReadPersonAge();
	cout << "Input height: ";
	ReadPersonHeight();
	cout << "Input weight: ";
	ReadPersonWeight(weight);
}