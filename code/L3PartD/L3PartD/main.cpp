// L3PartD.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
	double V0;
	double g = 9.8, s = 0, max = 0;
	int t = 0, max_time = 0;
	bool inAir = true;

	cout << "What is launch velocity? ";
	cin >> V0;

	//cout << "0\t0"<< endl;
	if (V0 <= 0)
	{
		inAir = false;
		cout << t << "\t" << s << endl;
	}
	while (inAir)
	{
		s = V0 * t - .5 * g * (t*t);
		if (s > max)
		{
			max = s;
			max_time = t;
		}
		if (s - 0.0 < 0)
		{
			s = 0;
			inAir = false;
			t--;
		}
		cout << t << "\t" << s << endl;
		t++;
	} 
	cout << "Total Time: " << t << "-seconds" << endl;
	cout << "Maximum Height: " << max << " @ " << max_time << "-seconds." << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
