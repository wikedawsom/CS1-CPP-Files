// L3PartE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "pch.h"
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
	double std_width, tol, width;

	cout << "Width: ";
	cin >> std_width;
	cout << "Tolerance: ";
	cin >> tol;

	for (int i = 60; i <= 85; i++)
	{
		width = std_width + (i - 70)*(0.0001);
		cout << static_cast<int>(i) << "\t" << fixed << setw(10) << setprecision(7) << width;
		if (fabs(width-std_width) < tol)
		{
			cout << "\t*" << endl;
		}
		else
			cout << endl;

	}
}


