#include <ctime>
#include <iostream>
#include <cstdlib>

using namespace std;

int diceRoll()
{
	srand(time(0));
	return rand() % 6 + 1;
}

int winCheck(int roll)
{
	//Return 0 if loss, 1 if win, and 2 if roll again
	switch (roll)
	{
	case(7):
	case(9):
	case(11):
		return 1;
	case(2):
	case(3):
	case(5):
		return 0;
	default:
		return 2;
	}
}

bool runtime()
{
	char playerInput;
	cout << "Enter \"r\" to roll (\"q\" to quit): ";
	cin >> playerInput;

	if (playerInput == 'q')
	{
		cout << "Thanks for playing." << endl;
		return false;
	}
	int roll1 = diceRoll();
	int roll2 = diceRoll();

	int win = winCheck(roll1 + roll2);

	cout << "You rolled a " << roll1 << " and a " << roll2 << ", for a total of: " << roll1 + roll2 << endl;
	
	switch (win)
	{
	case 1:
		cout << "Congratulations, you win!" << endl;
		return false;
	case 0:
		cout << "Sorry, you lose :(" << endl;
		return false;
	}

	cout << "Try again" << endl;
	return true;
}

int main()
{
	while (runtime()) {};
}