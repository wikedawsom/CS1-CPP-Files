#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

int diceRoll()
{
	return rand() % 6 + 1;
}

bool playOneGame()
{
	int playerNum, roll;
	cout << "Enter your lucky number (1 - 6): ";
	cin >> playerNum;

	while (playerNum < 1 || playerNum > 6)
	{
		cout << "Error: your number should be between 1 and 6." << endl;
		cout << "Enter your lucky number (1 - 6): ";
		cin >> playerNum;
	}

	for (int i = 1; i <= 3; i++)
	{
		roll = diceRoll();
		cout << "Roll #" << i << " is: " << roll << endl;

		if (roll == playerNum)
		{
			cout << "Congratulations, you win!" << endl;
			return true;
		}
	}
	cout << "Sorry, you lose :(" << endl;
	return false;
}

int main()
{
	int wins = 0, totalGamesPlayed = 0, wager, bank = 100;
	bool winOrLose;
	while(1)
	{
		srand(time(0));
		if (bank <= 0)
		{
			cout << "Your bank balance is $0.00." << endl
				<< "You won " << wins << " out of " << totalGamesPlayed << ", for a win rate of "
				<< 1.0*wins/totalGamesPlayed*100 << "%." << endl;
			break;
		}
		cout << "Account balance: $" << bank << endl;
		cout << "Enter amount to wager (0 to quit): ";
		cin >> wager;
		while (wager > bank || wager < 0)
		{
			cout << "Error: your wager must be greater than 0 and less than " << bank << endl;
			cout << "Enter amount to wager (0 to quit): ";
			cin >> wager;
		}
		if (wager == 0)
		{
			cout << "Your bank balance is $" << bank << endl
				 << "You won " << wins << " out of " << totalGamesPlayed << ", for a win rate of "
				 << 1.0*wins / totalGamesPlayed * 100 << "%." << endl;
			break;
		}
		winOrLose = playOneGame();
		if (winOrLose)
		{
			wins++;
			bank += wager;
		}
		else
			bank -= wager;
		totalGamesPlayed++;
	}
	cin >> wager;
}