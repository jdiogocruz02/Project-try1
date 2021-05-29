#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include "userinterface.h"
#include "structs.h"
#include "Game.h"
#include "Maze.h"
#include "Player.h"

using namespace std;

int main()
{
	int option;
	UI ui;
	option = ui.menudisplay();
	ui.choices(option);
	
}

