#include <iostream>
#include <ctime>
using namespace std;

class TicTacToe
{
private:
	const static int SIZE = 3;
	char grid[SIZE][SIZE];
	bool turn;

	bool isLegal(int pos1, int pos2)
	{
		return grid[pos1[pos2] == '-';
	}
	char winner;

public:
	void display()
	{
		for (int i = 0; i<SIZE; ++i)
		{
			for (int j = 0; j<SIZE; ++j)
				cout << grid[i][j] << " ";
			cout << endl;
		}
		cout << endl;
	}

	TicTacToe()
	{
		for (int i = 0; i<SIZE; ++i)
			for (int j = 0; j<SIZE; ++j)
				grid[i][j] = '-';
		turn = rand() % 2 == 1;
		winner = NULL;
	}

	void getMove(int *pos1, int *pos2)
	{
		cout << "Enter where you'd like to place your move:";
		cin >> *pos1 >> *pos2;
	}

	void move(int pos1, int pos2)
	{
		char c = turn ? 'X' : 'O';
		pos1--, pos2--;
		if (isLegal(pos1, pos2))
		{
			grid[pos1][pos2] = c;
			turn = !turn; //inverts turn
		}
		else
		{
			if (!turn)
			{
				cerr << "Error: Occupied !" << endl;
				getMove(&pos1, &pos2);
			}
			else AIMove(pos1, pos2);
			move(pos1, pos2);
		}
	}

	void AIMove(int &Pos3, int &Pos4)
	{
		Pos3 = rand() % 3 + 1;
		Pos4 = rand() % 3 + 1;
	}


	bool Won()
	{
		bool flag = false;
		int counter = 0;

		for (int count = 1; count <= 8; count++)
		{
			for (int i = 0; i<SIZE; ++i)
				switch (count)
			{
				case 1:
					counter += grid[i][i];
					break;

				case 2:

					counter += grid[i][2 - i];
					break;

				case 3:

					counter += grid[0][i];
					break;

				case 4:

					counter += grid[1][i];
					break;

				case 5:

					counter += grid[2][i];
					break;

				case 6:

					counter += grid[i][0];
					break;

				case 7:

					counter += grid[i][1];
					break;

				case 8:

					counter += grid[i][2];
					break;
			}
			if (counter == 3 * 'X')
			{
				winner = 'X';
				flag = true;
				break;
			}
			else if (counter == 3 * 'O')
			{
				flag = true;
				winner = 'O';
				break;
			}
		}
		return flag;
	}

	bool getMoveDecider()
	{
		return turn;
	}

	char getWinner()
	{
		return winner;
	}
};

