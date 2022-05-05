//  

#include <iostream>
#include <conio.h>

using namespace std;

void Input();
void Process();
void Draw();
void MovePlayer(int XDirection, int YDirection);

bool IsGoal();

//1. 지도를 초기화 한다.
int Map[10][10] =
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,1,0,0,0,1,0,0,1},
	{1,0,0,0,0,0,1,0,0,1},
	{1,0,0,0,0,0,1,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,0,1},
	{1,0,0,1,0,0,0,1,9,1},
	{1,1,1,1,1,1,1,1,1,1}
};

int PlayerX = 1;
int PlayerY = 1;

bool bIsRunning = true;
char Key;


int main()
{
	while (bIsRunning)
	{
		Input();
		Process();
		Draw();
	}

	return 0;
}

void Input()
{
	Key = _getch();
}

void Process()
{
	switch (Key)
	{
		//up
	case 'W':
	case 'w':
	{
		MovePlayer(0, -1);
		break;
	}
	//down
	case 'S':
	case 's':
	{
		MovePlayer(0, 1);
		break;
	}
	//left
	case 'A':
	case 'a':
	{
		MovePlayer(-1, 0);
		break;
	}
	//right
	case 'D':
	case 'd':
	{
		MovePlayer(1, 0);
		break;
	}

	//quit
	case 'Q':
	case 'q':
	{
		bIsRunning = false;
		break;
	}
	}
	if (IsGoal())
	{
		bIsRunning = false;
	}
}

void Draw()
{
	//화면을 지운다.
	system("cls");

	for (int Y = 0; Y < 10; ++Y)
	{
		for (int X = 0; X < 10; ++X)
		{
			if (PlayerX == X && PlayerY == Y)
			{
				cout << "P" << " ";
			}
			else if (Map[Y][X] == 0)
			{
				cout << " " << " ";
			}
			else if (Map[Y][X] == 1)
			{
				cout << "X" << " ";
			} 
			else if (Map[Y][X] == 9)
			{
				cout << "G" << " ";
			}
		}

		cout << endl;
	}
}

void MovePlayer(int XDirection, int YDirection)
{
	int NewplayerX = PlayerX + XDirection;
	int NewPlayerY = PlayerY + YDirection;

	if (Map[NewPlayerY][NewplayerX] == 0 || Map[NewPlayerY][NewplayerX] == 9)
	{
		PlayerX = NewplayerX;
		PlayerY = NewPlayerY;
	}
}

bool IsGoal()
{
	if (Map[PlayerY][PlayerX] == 9)
	{
		return true;
	}

	return false;
}