module student_1bib22401_Lab2_Variant8_Task2;
import <cmath>;


double RBPO::Lab2::Variant8::Task2::funcF1(double x)
{
	return pow(cos(x), 4) + pow(sin(x), 2) + 1 / 4 * pow(sin(2 * x), 2) - 1;
}
double RBPO::Lab2::Variant8::Task2::funcF2(double x)
{
	if (x < 3.2)
		return pow(x, 4) + 9;
	else
		return 54 * pow(x, 4) / (-5 * pow(x, 2) + 7);
}
static double funcA(int i)
{
	return (pow(-1, i) * (1 - ((double(pow(2, i)) / double(pow(2, i) + 1)))));
}
double RBPO::Lab2::Variant8::Task2::funcF3(int n)
{
	double f3 = 0;
	int i = 1;
	while (i <= n)
	{
		f3 += funcA(i);
		i++;
	}
	return f3;
}
double RBPO::Lab2::Variant8::Task2::funcF4(double e)
{
	double temp1 = 1, temp2 = 0;
	double S = 0;
	int i = 1;
	while (abs(temp1 - temp2) > e)
	{
		temp1 = funcA(i);
		temp2 = funcA(i + 1);
		S += funcA(i);
		i++;
	}
	return S;
}