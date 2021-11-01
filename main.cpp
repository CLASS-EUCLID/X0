#include <iostream>
#include <vector>
#include <conio.h>
/*
- - -
- - -
- - -
*/
int endX = 0, endY = 0;
/*
bool GameOver(char a[3][3], bool& player)
{
	
	if ((a[0][0] == a[0][1] && a[0][0] == a[0][2] || a[1][0] == a[1][1] && a[1][0] == a[1][2]|| a[2][0] == a[2][1] && a[2][0] == a[2][2] || a[0][0] == a[1][0] && a[0][0] == a[2][0] || a[0][1] == a[1][1] && a[0][1] == a[2][1] || a[0][2] == a[1][2] && a[0][2] == a[2][2] || a[0][0] == a[1][1] && a[0][0] == a[2][2] || a[0][2] == a[1][1] && a[0][2] == a[2][0]))
	{
		if(a[0][0] != '-' && a[2][2] != '-' && a[2][0] != '-' && a[1][1] != '-')
			std::cout << "CASTIGATORUL ESTE .... : " << player;
	}
	else
		return 0;
}
*/

int winner;

bool GameOver(char a[3][3], bool& player)
{
	bool moves = 0;
	
	if (a[0][0] == a[1][0] && a[0][0] == a[2][0])
	{
		if (a[0][0] == 'O')
		{
			winner = 0; return 1;
		}
		else if (a[0][0] == 'X')
		{
			winner = 1; return 1;
		} 
	}
	if (a[0][1] == a[1][1] && a[0][1] == a[2][1])
	{
		if (a[0][1] == 'O')
		{
			winner = 0; return 1;
		}
		else if (a[0][1] == 'X')
		{
			winner = 1; return 1;
		}
	}
	if (a[0][2] == a[1][2] && a[0][2] == a[2][2])
	{
		if (a[0][2] == 'O')
		{
			winner = 0; return 1;
		}
		else if (a[0][2] == 'X')
		{
			winner = 1; return 1;
		}
	}
	if (a[0][0] == a[0][1] && a[0][0] == a[0][2])
	{
		if (a[0][0] == 'O')
		{
			winner = 0; return 1;
		}
		else if (a[0][0] == 'X')
		{
			winner = 1; return 1;
		}
	}
	if (a[1][0] == a[1][1] && a[1][0] == a[1][2])
	{
		if (a[1][0] == 'O')
		{
			winner = 0; return 1;
		}
		else if (a[1][0] == 'X')
		{
			winner = 1; return 1;
		}
	}
	if (a[2][0] == a[2][1] && a[2][0] == a[2][2])
	{
		if (a[2][0] == 'O')
		{
			winner = 0; return 1;
		}
		else if (a[2][0] == 'X')
		{
			winner = 1; return 1;
		}
	}
	if (a[0][0] == a[1][1] && a[0][0] == a[2][2])
	{
		if (a[0][0] == 'O')
		{
			winner = 0; return 1;
		}
		else if (a[0][0] == 'X')
		{
			winner = 1; return 1;
		}
	}
	if (a[0][2] == a[1][1] && a[0][2] == a[2][0])
	{
		if (a[0][2] == 'O')
		{
			winner = 0;return 1;
		}
		else if (a[0][2] == 'X')
		{
			winner = 1;return 1;
		}
	}
	for (int i = 0; i < 2; i++)
		for (int j = 0; j < 2; j++)
		{
			if (a[i][j] == '-')
				moves = 1;
		}
	if (!moves)
	{
		winner = 2;
		return 1;
	}
	return 0;
}
int i;
int j;
void Draw(char a[3][3])
{
	system("cls");
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (endY == i && endX == j)
				std::cout << '&' << " ";
			else
			std::cout << a[i][j] << " ";
		}
		std::cout << std::endl;
	}
}


void Choose(char a[3][3], bool& player)
{

	bool lastPlayer = player;
	int displace;
	char character = _getch();

	if (character == 'w' && endY > 0 )
	{
		endY--;
	}
	else if (character == 'a' && endX > 0 )
	{
		endX--;

	}
	else if (character == 's' && endY < 2)
	{
		endY++;

	}
	else if (character == 'd' && endX < 2)
	{
		endX++;

	}
	else if (character == 'x')
	{
		if (player == 1 && a[endY][endX]=='-')
		{
			a[endY][endX] = 'X';
			player = 0;
		}
		else if (a[endY][endX] == '-')
		{
			a[endY][endX] = 'O';
			player = 1;
		}
	}

}



int main()
{
	
	bool gameOver = 0;
	bool player = 1;
	char a[3][3];
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			a[i][j] = '-';
		}
		std::cout << std::endl;
	}
	Draw(a);
	while (!gameOver)
	{
		Choose(a, player);
		Draw(a);
		gameOver = GameOver(a, player);
	}
	endX = -1;
	endY = -1;
	Draw(a);
	if (winner == 1)
	{
		std::cout << "Winner is ... X";
	}
	else if (winner == 0)
		std::cout << "Winner is ... O";
	else
		std::cout << "Remiza .....";
}
