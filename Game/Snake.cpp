#include <iostream>
#include <conio.h>
using namespace std;

bool gameOver;
const int width = 20;
const int height = 15;
int x, y, fruitx, fruity, score;
enum eDirection {STOP = 0, LEFT, RIGHT, UP, DOWN};
eDirection dir;

void Setup() {
	gameOver = false;
	dir = STOP;
	x = width / 2-1;
	y = height / 2-1;
	fruitx = rand() % width;
	fruitx = rand() % height;
	score = 0;
}

void Draw() {
	system("cls");
	for (int i = 0; i < width; i++)
	{
		cout << "#";
	}
	
	for (int i = 0; i < height; i++)
	{
		for (int j= 0; j<width; j++) 
		{
			if (j == 0 || j == width - 1) 

				cout << "#";
				if (i == y && j == x)
					cout << "0";
				else if (i == fruitx && j == fruitx)
					cout << "f";
				else cout << " ";
		}		
		cout << endl;
	}
	for (int i = 0; i < width+1; i++)
	{
		cout << "#";
	}
		
}

void Input() {
	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}
}

void Logic() {
	switch (dir)
	{
	case LEFT:
		x--;
		break;
	case RIGHT:
		x++;
		break;
	case UP:
		y--;
		break;
	case DOWN:
		y++;
		break;
	}
}
int main() 
{
	int a, c;
	while (a == true)
	{
		if (c == 'z')
		{
			a = false;
		}

		Setup();
		while (!gameOver) {
			Draw();
			Input();
			Logic();
		}
		return 0;
	}
}