#include <iostream>
#include <windows.h>
#include <clocale>
#include <Windows.h>
#include <string>

import student_1bib22401_Lab2_Variant8_Task1;
import student_1bib22401_Lab2_Variant8_Task2;
import student_1bib22401_Lab2_Variant8_Task3;
import student_1bib22401_Lab2_Variant8_Task4;
import student_1bib22401_Lab2_Variant8_Task5;


using namespace std;

int main(int argc, char* argv[])
{
	int swcase;
	string continue_;
	while(true)
	{
		cout << "Select a task 1-5: ";
		cin >> swcase;
		switch (swcase)
		{
		case(1):
		{
			cout << "variant 8" << endl;
			cout << "Task 1" << endl;
			double x;
			cout << "Enter the parameter x: ";
			cin >> x;
			cout << "f1 = " << RBPO::Lab2::Variant8::Task1::funcF1(x) << endl;
			cout << "f2 = " << RBPO::Lab2::Variant8::Task1::funcF2(x) << endl;
			int n;
			cout << "Enter the number of sum elements n: ";
			cin >> n;
			cout << "f3 = " << RBPO::Lab2::Variant8::Task1::funcF3(n) << endl;
			double e = 0;
			cout << "Enter the accuracy e: ";
			cin >> e;
			cout << "f4 = " << RBPO::Lab2::Variant8::Task1::funcF4(e) << endl;
			break;
		}
		case(2):
		{
			cout << "variant 8" << endl;
			cout << "Task 2" << endl;
			double x;
			cout << "Enter the parameter x: ";
			cin >> x;
			cout << "f1 = " << RBPO::Lab2::Variant8::Task2::funcF1(x) << endl;
			cout << "f2 = " << RBPO::Lab2::Variant8::Task2::funcF2(x) << endl;
			int n;
			cout << "Enter the number of sum elements n: ";
			cin >> n;
			cout << "f3 = " << RBPO::Lab2::Variant8::Task2::funcF3(n) << endl;
			double e = 0;
			cout << "Enter the accuracy e: ";
			cin >> e;
			cout << "f4 = " << RBPO::Lab2::Variant8::Task2::funcF4(e) << endl;
			break;
		}
		case(3):
		{
			cout << "variant 8" << endl;
			cout << "Task 3" << endl;
			double x;
			cout << "Enter the parameter x: ";
			cin >> x;
			cout << "f1 = " << RBPO::Lab2::Variant8::Task3::funcF1(x) << endl;
			cout << "f2 = " << RBPO::Lab2::Variant8::Task3::funcF2(x) << endl;
			int n;
			cout << "Enter the number of sum elements n: ";
			cin >> n;
			cout << "f3 = " << RBPO::Lab2::Variant8::Task3::funcF3(n) << endl;
			double e = 0;
			cout << "Enter the accuracy e: ";
			cin >> e;
			cout << "f4 = " << RBPO::Lab2::Variant8::Task3::funcF4(e) << endl;
			break;
		}
		case(4):
		{
			cout << "variant 8" << endl;
			cout << "Task 4" << endl;
			double x;
			cout << "Enter the parameter x: ";
			cin >> x;
			cout << "f1 = " << RBPO::Lab2::Variant8::Task4::funcF1(x) << endl;
			cout << "f2 = " << RBPO::Lab2::Variant8::Task4::funcF2(x) << endl;
			int n;
			cout << "Enter the number of sum elements n: ";
			cin >> n;
			cout << "f3 = " << RBPO::Lab2::Variant8::Task4::funcF3(n) << endl;
			double e = 0;
			cout << "Enter the accuracy e: ";
			cin >> e;
			cout << "f4 = " << RBPO::Lab2::Variant8::Task4::funcF4(e) << endl;
			break;
		}
		case(5):
		{
			cout << "variant 8" << endl;
			cout << "Task 5" << endl;
			double x;
			cout << "Enter the parameter x: ";
			cin >> x;
			cout << "f1 = " << RBPO::Lab2::Variant8::Task5::funcF1(x) << endl;
			cout << "f2 = " << RBPO::Lab2::Variant8::Task5::funcF2(x) << endl;
			int n;
			cout << "Enter the number of sum elements n: ";
			cin >> n;
			cout << "f3 = " << RBPO::Lab2::Variant8::Task5::funcF3(n) << endl;
			double e = 0;
			cout << "Enter the accuracy e: ";
			cin >> e;
			cout << "f4 = " << RBPO::Lab2::Variant8::Task5::funcF4(e) << endl;
			break;
		}
		}
		int f = 0;
		while (1) {
			cout << "Continue testing? yes/no: ";
			cin >> continue_;
			if (continue_ == "yes")
				break;
			else if (continue_ == "no") {
				f = 1;
				break;
			}
			else cout << "incorrect\n";
		}
		if (f) break;
	}
}
