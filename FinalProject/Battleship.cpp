//Battleship
//by: Christian Harris and Courtney Jo Young

#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>
#include <cmath>
#include <ctime>

using namespace std;

class PlayingField
{
public:
	PlayingField()
	{
		for (int r = 0; r < 10; r++)
		{
			for (int c = 0; c < 10; c++)
			{
				board[r][c] = 'o';
				enemyBoard[r][c] = 'o';
			}
		}
		ships.push_back("11");
		ships.push_back("222");
		ships.push_back("333");
		ships.push_back("4444");
		ships.push_back("55555");
		sunkenShips = 0;
	}
	int PlaceShip(int r, int c, int shipNum, int direction)
	{
		int origR = r;
		int origC = c;
		for (int i = 0; i < ships[shipNum].length(); i++) // Checks if the ship will fit
		{
			if (r < 0 || r > 9 || c < 0 || c > 9 || board[r][c] != 'o')
				return 1;
			//cout << "test r: " << r << ", test c: " << c << endl;
			switch (direction)
			{
			case 1:
				r --;
				break;
			case 2:
				r ++;
				break;
			case 3:
				c --;
				break;
			case 4:
				c ++;
				break;
			}
			
		}
		r = origR;
		c = origC;
		for (int i = 0; i < ships[shipNum].length(); i++)
		{
			if (board[r][c] != 'o')
				return 1;
			//cout << "r: " << r << ", c: " << c << endl;
			board[r][c] = ships[shipNum].at(i);
			switch (direction)
			{
			case 1:
				r -= 1;
				break;
			case 2:
				r += 1;
				break;
			case 3:
				c -= 1;
				break;
			case 4:
				c += 1;
				break;
			}
		}
		return 0;
	}
	int hitOrMiss(int r, int c)
	{
		if (r < 0 || r > 9 || c < 0 || c > 9)
			return 3;
		if (board[r][c] == 'o')
		{
			board[r][c] = 'w';
			enemyBoard[r][c] = 'w';
			return 0;
		}
		else if (board[r][c] == 'x' || board[r][c] == 'w')
		{
			return 1;
		}
		else
		{
			if (checkSunk(r, c))
			{
				cout << "**********************************" << endl;
				cout << "***********Ship is sunk***********" << endl;
				cout << "**********************************" << endl;
			}
				enemyBoard[r][c] = 'x';
				board[r][c] = 'x';
			return 2;
		}
	}
	bool checkSunk(int r, int c)
	{
		bool sunk = false;
		int shipNum = 0;
		switch (board[r][c])
		{
		case '1':
			shipNum = 0;
			break;
		case '2':
			shipNum = 1;
			break;
		case '3':
			shipNum = 2;
			break;
		case '4':
			shipNum = 3;
			break;
		case '5':
			shipNum = 4;
			break;
		}
		int i = 0;
		while (i < ships[shipNum].length() && ships[shipNum].at(i) == 'x')
			i++;
		if (i >= ships[shipNum].length() - 1)
		{
			sunk = true;
			sunkenShips += 1;
		}
		ships[shipNum].at(i) = 'x';
		return sunk;
	}
	void showBoard()
	{
		cout << "\t";
		for (int i = 1; i < 11; i++)
			cout << i << " ";
		cout << endl << endl;
		for (int r = 0; r < 10; r++)
		{
			cout << static_cast<char>('A' + r) << "\t";
			for (int c = 0; c < 10; c++)
				cout << board[r][c] << " ";
			cout << endl;
		}
		cout << endl;
	}
	void hiddenShipsBoard()
	{
		cout << "\t";
		for (int i = 1; i < 11; i++)
			cout << i << " ";
		cout << endl << endl;
		for (int r = 0; r < 10; r++)
		{
			cout << static_cast<char>('A' + r) << "\t";
			for (int c = 0; c < 10; c++)
				cout << enemyBoard[r][c] << " ";
			cout << endl;
		}
		cout << endl;
	}
	int getSunkenShips()
	{
		return sunkenShips;
	}
private:
	char board [10][10];
	char enemyBoard[10][10]; //This is the version of the board that the other player sees when taking shots
	vector <string> ships;
	int sunkenShips;
};
class Battleship
{
public:
	Battleship()
	{
		P1 = PlayingField();
		P2 = PlayingField();
	}
	void PlayGame()
	{
		int playerCount = 0;
		string players;
		while (playerCount != 1 && playerCount != 2)
		{
			cout << "**Welcome to Battleship**" << endl;
			cout << "How many players do you have? (1 or 2): ";
			cin >> players;
			playerCount = stoi(players);
		}
		int winner = 0;
		if (playerCount == 1)
			winner = Start(1);
		else
			winner = Start(2);
		cout << "Game Over, Player " << winner << " wins!" << endl;

	}
private:
	int Start(int numPlayers)
	{
		cout << "Player one, place your ships." << endl;
		PlaceShips(P1);
		if (numPlayers == 1)
		{
			AIPlaceShips(P2);
			cout << "AI has placed their ships" << endl;
		}
		else
		{
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" // I don't know how to clear out the cmd window, so this is to
				<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"  //   deter Player 2 from cheating
				<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << endl;
			cout << "Player two, place your ships." << endl;
			PlaceShips(P2);
			cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" // and this one is to deter P1 from cheating
				<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
				<< "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n ";
		}
		
		while (1)
		{
			string temp;
			cout << "Player One's Turn (press enter to continue).";
			getline(cin, temp); // Had to put two getline()'s here in case the input buffer already had 
			getline(cin, temp); //   a newline character left over from a previous cin
			
			for (int i = P1.getSunkenShips(); i < 5; i++)
			{
				cout << "Target Board:" << endl;
				P2.hiddenShipsBoard();
				PlayerShoot(P2);
				if (P2.getSunkenShips() >= 5)
				{
					return 1;
				}
			}
			P2.hiddenShipsBoard();
			
			cout << "Player Two's Turn (press enter to continue).";
			getline(cin, temp);
			getline(cin, temp);

			for (int i = P2.getSunkenShips(); i < 5; i++)
			{
				if (numPlayers == 1)
				{
					AIShoot(P1);
					P1.showBoard();
				}
				else
				{
					cout << "Target Board: " << endl;
					P1.hiddenShipsBoard();
					PlayerShoot(P1);
				}
				if (P1.getSunkenShips() >= 5)
				{
					return 2;
				}
			}
			if (numPlayers == 2)
				P1.hiddenShipsBoard();
		}
	}
	void AIShoot(PlayingField &player)
	{
		while (1)
		{
			int c = rand() % 10;
			int r = rand() % 10;
			if (player.hitOrMiss(r, c) != 1)
				return;
		}
	}
	void PlayerShoot(PlayingField &opponent)
	{
		bool again = true;
		int hitmiss = 1;
		string shot = "Q";
		int r = 11, c = 11;
		bool repeat = true;
		
		while (shot.length() < 2 || shot.length() > 3)
		{
			cout << "Enter target co-ordinates (from A1 to J10): ";
			cin >> shot;
		}
		r = static_cast<int>(toupper(shot[0]) - 'A');
		c = stoi(shot.substr(1, shot.length() - 1)) - 1;
		
		hitmiss = opponent.hitOrMiss(r, c);
		if (hitmiss != 1)
			again = false;
		while (again)
		{
			if (hitmiss == 0 || hitmiss == 2)
			{
				cout << "You already shot there, try somewhere else." << endl;
			}
			else if (hitmiss == 3)
			{
				cout << "You need to choost a target within the grid." << endl;
			}
			cout << "Enter target co-ordinates (from A1 to J10): ";
			cin >> shot;
			r = static_cast<int>(toupper(shot[0]) - 'A');
			c = stoi(shot.substr(1, shot.length() - 1));
			hitmiss = opponent.hitOrMiss(r, c);
			if (hitmiss != 1)
				again = false;
		}

	}
	void AIPlaceShips(PlayingField &player)
	{
		for (int num = 0; num < 5; num++)
		{
			int tryAgain = 1;
			while (tryAgain)
			{
				int r, c, dir;
				
				r = rand() % 10;
				c = rand() % 10;
				dir = rand() % 4;
				
				tryAgain = player.PlaceShip(r, c, num, dir);
			}
		}
	}
	void PlaceShips(PlayingField &player)
	{
		for (int num = 0; num < 5; num++)
		{
			int tryAgain = 1;
			while (tryAgain)
			{
				
				string coords = "A";
				int r = -1, c = 10, dir;
				char direction;
				bool repeat = true;
				
				while (coords.length() < 2 || coords.length() > 3)
				{
					cout << "Enter co-ordinates of the stern of ship #" << num + 1 << " (from A1 to J10): ";
					cin >> coords;
				}
				r = static_cast<int>(toupper(coords[0]) - 'A');
				c = stoi(coords.substr(1, coords.length() - 1)) - 1;
				
				cout << "Enter direction (\"u\" for up, \"d\" for down, \"l\" for left, \"r\" for right: ";
				cin >> direction;
				switch (direction)
				{
				case 'u':
					dir = 1;
					break;
				case 'd':
					dir = 2;
					break;
				case 'l':
					dir = 3;
					break;
				case 'r':
					dir = 4;
					break;
				default:
					dir = 1;
				}
				tryAgain = player.PlaceShip(r, c, num, dir);
				if (tryAgain == 1)
					cout << "Error: does not fit." << endl;
				player.showBoard();
			}
		}
	}
	PlayingField P1;
	PlayingField P2;
};

int main() {
    
    srand(time(0));
	Battleship game = Battleship();
	game.PlayGame();
	cout << "Play Again? (y/n): ";
	char playAgain;
	cin >> playAgain;
	while (playAgain == 'y')
	{
		srand(time(0));
		Battleship game = Battleship();
		game.PlayGame();
		cout << "Play Again? (y/n): ";
		cin >> playAgain;
	}
    return 0;
    
}
