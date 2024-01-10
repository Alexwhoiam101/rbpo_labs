module student_1bib22401_Lab2_Variant8_Task3;
import <cmath>;


double RBPO::Lab2::Variant8::Task3::funcF1(double x)
{
	return pow(cos(x), 4) + pow(sin(x), 2) + 1 / 4 * pow(sin(2 * x), 2) - 1;
}