#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;
const double PI = 3.1415926535;

double d_to_r(double d)
{
	d = fmod(d, 360);
	double r = d * PI / 180.0;
	return r;
}
int main()
{
	cout << "Degrees" << setw(10) << "Sin" << setw(10) << "Cos" << setw(25) << "Tan" << endl;
	for (int d = 0; d <= 360; d += 10)
	{
		cout << d << "\t";
		cout << fixed << setw(10) << setprecision(4) << sin(d_to_r(d));
		cout << fixed << setw(10) << setprecision(4) << cos(d_to_r(d));
		cout << fixed << setw(25) << setprecision(4) << tan(d_to_r(d)) << endl;
	}
	int x;
	cin >> x;
}