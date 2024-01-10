export module student_1bib22401_Lab2_Variant8_Task1;

import <cmath>;

namespace RBPO
{
	namespace Lab2
	{
		namespace Variant8
		{
			namespace Task1
			{
				export double funcF1(double x)
				{
					return pow(cos(x), 4) + pow(sin(x), 2) + 1 / 4 * pow(sin(2 * x), 2) - 1;
				}
				export double funcF2(double x)
				{
					return (x < 3.2) ? pow(x, 4) + 9 : 54 * pow(x, 4) / (-5 * pow(x, 2) + 7);
				}
				double funcA(int i)
				{
					return (pow(-1, i) * (1 - ((double(pow(2, i)) / double(pow(2, i) + 1)))));
				}
				export double funcF3(int n)
				{
					double f3 = 0;
					for (int i = 1; i <= n; i++)
					{
						f3 += funcA(i);
					}
					return f3;
				}
				export double funcF4(double e)
				{
					double temp1=1, temp2=0;
					double S=0;
					for(int i = 1; abs(temp1 - temp2) > e;i++)
					{
						temp1 = funcA(i);
						temp2 = funcA(i + 1);
						S += funcA(i);
					}
					return S;
				}

			}
				
		}
	}
}


