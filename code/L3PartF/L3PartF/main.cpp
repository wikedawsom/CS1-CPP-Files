#include <iostream>
#include <iomanip>
using namespace std;
// Please add the code necessary to calculate the factorial of the number represented by N
// Use a proper return statement to return the result of this calculation
double factorial(int N) {
	if (N == 0 || N == 1)
		return 1;
	double fact = 1;
	for (int i = N; i > 0; i--)
	{
		fact *= i;
	}
	return fact;
	// Please place your code within the {} braces
}
// Please do not change main()
int main() {
	int N;
	cin >> N;
	cout << "Equals " << fixed << setprecision(0) << noshowpoint << factorial(N) << endl;
	return 0;
}
