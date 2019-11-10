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
			
			if (i == 0 || k == 0 || i == height - 1 || k == width - 1) {
				cout << "*";
			}
			else {
				cout << " ";
			}
		cout << endl;
	}
	cout << "0";
	cin >> width;
}