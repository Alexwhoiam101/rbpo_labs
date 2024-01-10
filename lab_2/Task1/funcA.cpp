module student_1bib22401_Lab2_Variant8_Task3;
import <cmath>;
double RBPO::Lab2::Variant8::Task3::funcA(int i)
{
	return (pow(-1, i) * (1 - ((double(pow(2, i)) / double(pow(2, i)+1)))));
}