// Christian Harris
#include <iostream>
using namespace std;
int main()
{
	double num, sum = 0;
	//cin >> num;

	do
	{
		cout << "Enter Positive Number to Add or Enter Zero or Negative Number to End : ";
		cin >> num;
		if (num > 0) sum += num;
	} while (num > 0);
	cout << "Sum of entered numbers: " << sum << endl;
}