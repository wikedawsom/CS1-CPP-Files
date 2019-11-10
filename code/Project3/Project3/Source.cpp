#include <iostream>
using namespace std;
int absolute(int x)
{
	return (x >= 0) ? x : -x;
}
int min(int a, int b)
{
	return (a < b) ? a : b;
}
int max(int a, int b)
{
	return (a > b) ? a : b;
}
void swapEm(int &a, int &b)
{
	int temp = b;
	b = a;
	a = temp;
}
int main()
{
	cout << "Absolute(-10) = " << absolute(-10) << ", Absolute(0) = " << absolute(0) 
		<< ", Absolute(6) = " << absolute(6) << endl  << endl;
	cout << "min(-2, 3) = "<<min(-2, 3) << ", min(3, -4) = " << min(3, -4) 
		<< ", min(0, -1) = " << min(0, -1) << ", min(0, 0) = " << min(0, 0) << endl  << endl;
	cout << "max(-2,3) = " << max(-2, 3) << ", max(3, -4) = " << max(3, -4) 
		<< ", max(0, -1) = " << max(0, -1) << ", max(0, 0) = " << max(0, 0) << endl << endl;
	int a = 4, b = 8;
	cout << "a = " << a << ", b = " << b << endl;
	swapEm(a, b);
	cout << "After swapEm(a,b), a = " << a << ", b = " << b << endl;

	cin >> a;
	return 0;
}