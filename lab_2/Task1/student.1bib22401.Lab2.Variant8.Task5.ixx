export module student_1bib22401_Lab2_Variant8_Task5;
import <cmath>;

namespace RBPO
{
	namespace Lab2
	{
		namespace Variant8
		{
			namespace Task5
			{
				export double funcF1(double x);
				export double funcF2(double x);
				double funcA(int i);
				export double funcF3(int n);
				export double funcF4(double e);
			}
				
		}
	}
}

module :private;


double RBPO::Lab2::Variant8::Task5::funcF1(double x)
{
	return pow(cos(x), 4) + pow(sin(x), 2) + 1 / 4 * pow(sin(2 * x), 2) - 1;
}
double RBPO::Lab2::Variant8::Task5::funcF2(double x)
{
	return (x < 3.2) ? pow(x, 4) + 9 : 54 * pow(x, 4) / (-5 * pow(x, 2) + 7);
}
double RBPO::Lab2::Variant8::Task5::funcA(int i)
{
	return (pow(-1, i) * (1 - ((double(pow(2, i)) / double(pow(2, i) + 1)))));
}
double RBPO::Lab2::Variant8::Task5::funcF3(int n)
{
	double f3 = 0;
	for (int i = 1; i <= n; i++)
	{
		f3 += funcA(i);
	}
	return f3;
}
double RBPO::Lab2::Variant8::Task5::funcF4(double e)
{
	double temp1 = 1, temp2 = 0;
	double S = 0;
	for (int i = 1; abs(temp1 - temp2) > e; i++)
	{
		temp1 = funcA(i);
		temp2 = funcA(i + 1);
		S += funcA(i);
	}
	return S;
}


