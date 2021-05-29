#include "userinterface.h"


using namespace std;

template<typename T> std::istream& read(T& var) {
	std::cin.clear();
	std::cin.ignore(1000, '\n');
	return (std::cin >> var);
}

int UI::menudisplay()
{
	int choice;
	cout << "     Menu     " << endl;
	cout << "1. Rules" << endl;
	cout << "2. Play" << endl;
	cout << "3. Winners" << endl;
	cout << "0. Exit" << endl;
	cin >> choice;
	return choice;
}

void UI::choices(int choice)
{
	if (choice == 1)
	{
		int ret = 0;
		cout << ifstream("Rules.txt").rdbuf() << endl; // output the rules txt file
		cout << "To return to the main menu input 2: ";
		cin >> ret;
		if (ret == 2)
		{
			menudisplay();
		}
	}
	if (choice == 2)
	{
		cout << "What maze do you want to play? (Input maze number)" << endl;
		bool exists = false;
		while (exists == false)
		{
			string n;
			bool valid = false;
			while (valid == false) // check if maze number is valid
			{
				cin >> n;
				int i, totChar;
				totChar = 0;
				for (i = 0; n[i] != '\0'; i++)
				{
					totChar++;
				}
				if (totChar == 1) // corrects if the input was a single digit number
				{
					n = "0" + n;
					valid = true;
					break;
				}
				if (totChar == 2)
				{
					n = n;
					valid = true;
					break;
				}
				else //no 3 digit mazes here
				{
					valid = false;
					cout << "Input a valid maze number" << endl;
				}
			}
			string filename = "MAZE_" + n + ".txt";
			if (!ifstream(filename)) //check if the file for the maze exists and is openable
			{
				exists = false;
				cout << "Maze doesn't exist yet, maybe in the next dlc, for now try another one" << endl;
			}
			else
			{
				exists = true;
				Game game;
				game.play();
			}
		}
	}
	if (choice == 3)
	{
			
	}
	else
	{
		exit(1);
	}
}
