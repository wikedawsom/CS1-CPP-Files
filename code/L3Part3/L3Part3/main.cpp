// Christian Harris
#include <iostream>
using namespace std;
int main()
{
	int width, height;
	cin >> width;
	cin >> height;
	for (int i = 0; i < height; i++)
	{
		for (int k = 0; k < width; k++)
			cout << "*";
		cout << endl;
	}
	cout << "0";
	cin >> width;
}