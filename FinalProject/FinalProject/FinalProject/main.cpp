#include<iostream>
#include <cmath>
#include"bezier.h"
#include "dualNumber.h"

#include "armadillo"

using namespace arma;
using namespace std;

int main()
{
	double controlPoints[] = { 0, 0, 3, 5, 6, -3, 5, 0 };
	Bezier b( controlPoints, 3 );
	b.saveInFile( "bezierPoints.txt" );


	mat real_mat;
	mat dual_mat;
	double real_arr[3][3] = {0.0};
	double dual_arr[3][3] = {0.0};

	for (int k = -1; k <= 1; ++k)
	{
		for (int m = -1; m <= 1; ++m)
		{
			double real = 0.0;
			double dual = 0.0;
			Dual omiga;

			for (int i = 0; i < 20; ++i)
			{
				real += cos((k - m) * (2 * 180.0 * i) / 20);
				dual += sin((k - m) * (2 * 180.0 * i) / 20);
			}

			omiga.SetReal(real);
			omiga.SetDual(dual);

			real_arr[k+1][m+1] = real;
			dual_arr[k+1][m+1] = dual;
		}
	}

	real_mat << real_arr[0][0] << real_arr[0][1] << real_arr[0][2] << endr
			 << real_arr[1][0] << real_arr[1][1] << real_arr[1][2] << endr
			 << real_arr[2][0] << real_arr[2][1] << real_arr[2][2] << endr;

	dual_mat << dual_arr[0][0] << dual_arr[0][1] << dual_arr[0][2] << endr
			 << dual_arr[1][0] << dual_arr[1][1] << dual_arr[1][2] << endr
			 << dual_arr[2][0] << dual_arr[2][1] << dual_arr[2][2] << endr;

	real_mat.print("real mat");
	dual_mat.print("dual mat");

  getchar();
}
