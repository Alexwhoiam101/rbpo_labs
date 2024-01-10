#include <iostream>

import Math;
using namespace std;
int main()
{
	setlocale(LC_ALL, "ru");
	cout << "1 for test tack2, like not test, but input for test func() :)" << endl << "0 for autotest" << endl;
	int temp = 0;
	cin >> temp;
	if (temp) {
		double re, im;
		cout << "Input Real and Imag num:" << endl;
		cin >> re >> im;
		Complex c_num(re, im);

		double chisl, znam;
		cout << "Input Above and Below num:" << endl;
		cin >> chisl >> znam;
		Rational r_num(chisl, znam);
		double d_num;
		cout << "Input double:" << endl;
		cin >> d_num;

		Rational answ = f(r_num);
		double a = answ.Nominator(), b = answ.Denominator();

		cout << "f(" << c_num << ") = " << f(c_num) << endl;
		cout << "f(" << r_num << ") = " << f(r_num) << " = " << a / b << endl;
		cout << "f(" << d_num << ") = " << f(d_num) << endl;

		return 0;

	}
	Complex a(2, -1);
	Complex b(9.1, -4.5);
	Rational c(3, 5);
	Rational d(2, 4);
	double e = -9;
	cout << "a = " << a << " Real = " << a.Re() << " Imag = " << a.Im() << " Mod = " << a.Mod() << " Arg = " << a.Arg() << endl;
	cout << "a+b = " << a << " + " << b << " = " << a + b << endl;
	cout << "a-b = " << a << " + " << b << " = " << a - b << endl;
	cout << "a*b = " << a << " + " << b << " = " << a * b << endl;
	cout << "a/b = " << a << " + " << b << " = " << a / b << endl;
	cout << "a+c = " << a << " + " << d << " = " << a + e << endl;
	cout << "a+b = " << c << " + " << d << " = " << c + d << endl;
	cout << "a-b = " << c << " - " << d << " = " << c - d << endl;
	cout << "a*b = " << c << " * " << d << " = " << c * d << endl;
	cout << "a/b = " << c << " / " << d << " = " << c / d << endl;
	cout << "a = " << c << " Числитель = " << c.Nominator() << " Знаменатель = " << c.Denominator() << " double = " << double(c) << endl;
	cout << "f(" << a << ") = " << f(a) << endl;
	cout << "f(" << d << ") = " << f(d) << endl;
	cout << "f(" << e << ") = " << f(e) << endl;
	return 0;
}