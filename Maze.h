//adapts the display of the maze o the playerand robot moves
#include <iostream>
#include <windows.h>
#include <fstream>
#include <string>
#include <vector>
#include "structs.h"
#ifndef Maze_H
#define Maze_H


class Maze {
public:
	Maze(int numRows, int numCols,string filename);
	Maze() = default;
	int getnumRows(string filename) const;
	int getnumCols(string filename) const;
private:
	vector<char[]>mazeo;
	string filename;
	int numRows, numCols;
	// data structure that represents the posts
};

#endif