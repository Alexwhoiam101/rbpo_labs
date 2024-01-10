module student_1bib22401_Lab2_Variant8_Task4:funcF3;
import <cmath>;
import :funcA;
double RBPO::Lab2::Variant8::Task4::funcF3(int n)
{
	double f3 = 0;
	int i = 1;
	do
	{
		f3 += funcA(i);
		i++;
	} while (i <= n);
	return f3;
}