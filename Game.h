//is the law,enforces police brutality
//reads initial maze
//has player and maze attributes and a robot data structure
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>
#include <fstream>
#include "Player.h"
#include "Robot.h"
#include "Maze.h"
#include "Post.h"
#ifndef Game_H
#define Game_H


class Game {
public:
	Game(const string& filename);
	Game() = default;
	bool play(); 
	void moveRobots();
	void winners();
private:
	void showGameDisplay() const;
	bool isValid();
	vector <char[20]> mazeo;
	Maze maze;
	Player player;
	Position expos;
	vector<Robot> robots;
	vector<Post> posts;
	vector<Position> exits;
	//other attributes
};

#endif