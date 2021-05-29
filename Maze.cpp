#include "Maze.h"
using namespace std;


Maze::Maze(int numRows, int numCols, string filename)
{
	int linen = 0;
	int chara = 0;
	vector<char[20]> mazeo;
	string line;
	ifstream file(filename);
	while (!file.eof()) // loop to output the contents of the txt file while saving each line as an element in an array, loops ends when contents of the file end
	{
		getline(file, line); //get one line from the file
		mazeo[linen][chara] = line[chara]; //save the line in the array
		cout << mazeo[linen] << endl; //output the line
		chara++;
	}
	file.close();
	numRows = getnumRows(filename);
	numCols = getnumCols(filename);
}

int Maze::getnumRows(string filename) const
{ 
	return mazeo.size();
}

int Maze::getnumCols(string filename) const
{
	return strlen(mazeo[0]);
}

