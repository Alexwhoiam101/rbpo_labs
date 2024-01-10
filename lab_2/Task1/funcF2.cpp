module student_1bib22401_Lab2_Variant8_Task3;
import <cmath>;
double RBPO::Lab2::Variant8::Task3::funcF2(double x)
{
	if (x < 3.2)
		return pow(x, 4) + 9;
	else
		return 54 * pow(x, 4) / (-5 * pow(x, 2) + 7);
}