#include <iostream>
#include <cmath>
using namespace std;

double factorial(double N) {
	if (N == 0 || N == 1)
		return 1;
	double fact = 1;
	for (int i = N; i > 0; i--)
	{
		fact *= i;
	}
	return fact;
}
double E_to_X(double X) 
{
	double e = 1, prev_E = 1;
	double precision = 1;
	double count = 1;
	while (precision > .0001)
	{
		e += pow(X, count)/factorial(count);
		precision = fabs(e - prev_E);
		prev_E = e;
		count++;
	}
	return e;
}

int main()
{
	double power;
	cin >> power;
	cout << E_to_X(power) << endl;
	cin >> power;
}