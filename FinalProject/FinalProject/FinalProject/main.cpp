#include<iostream>
#include <cmath>
#include"bezier.h"
#include "dualNumber.h"

#include "armadillo"

using namespace arma;
using namespace std;
vector<Dual> point;

void calcOmiga(void)
{
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

}


void calcY(void)
{
	mat real_mat;
	mat dual_mat;
	double real_arr[3] = {0.0};
	double dual_arr[3] = {0.0};

	for (int m = -1; m <= 1; ++m)
	{
		double real = 0.0;
		double dual = 0.0;

		Dual omiga;

		for (int i = 0; i < 20; ++i)
		{
			Dual e_num;
			Dual z_num = point.at(i);
			Dual result;

			e_num.SetReal(cos(m * (2 * 180.0 * i) / 20));
			e_num.SetDual(sin(m * (2 * 180.0 * i) / 20));

			result = z_num * e_num;

			real += result.GetReal();
			dual += result.GetDual();
		}

		omiga.SetReal(real);
		omiga.SetDual(dual);

		real_arr[m+1] = real;
		dual_arr[m+1] = dual;
	}

	real_mat << real_arr[0] << real_arr[1] << real_arr[2] << endr;
	dual_mat << dual_arr[0] << dual_arr[1] << dual_arr[2] << endr;

	real_mat.print("real mat");
	dual_mat.print("dual mat");
}


void load_File(char *file)
{
	double t, Px, Py;
	ifstream inFile(file, ios::out);

	if (!inFile)
	{
		cerr<<"File" << file << "could not be edited" << endl;
		exit(1);
	}

	for (int i = 0; i < 20; ++i)
	{
		Dual d_num;
		inFile >> Px >> Py;
		d_num.SetReal(Px);
		d_num.SetDual(Py);

		point.push_back(d_num);
	}		
}

int main()
{
	double controlPoints[] = { 0, 0, 3, 5, 6, -3, 5, 0 };
	Bezier b( controlPoints, 3 );
	b.saveInFile( "bezierPoints.txt" );
	load_File("bezierPoints.txt");

	calcOmiga();
	calcY();
	
	getchar();
}
