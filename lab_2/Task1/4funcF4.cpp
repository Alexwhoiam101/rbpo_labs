module student_1bib22401_Lab2_Variant8_Task4:funcF4;
import <cmath>;
import :funcA;
double RBPO::Lab2::Variant8::Task4::funcF4(double e)
{
	double temp1, temp2;
	double S = 0;
	int i = 1;
	do
	{
		temp1 = funcA(i);
		temp2 = funcA(i + 1);
		S += funcA(i);
		i++;
	} while (abs(temp1 - temp2) > e);
	return S;
}