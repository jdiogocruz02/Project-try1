#include "Game.h"
#define sizex(a) (sizeof(a) / sizeof(*a))
using namespace std;

Game::Game(const string& filename)
{
	int i = 0;
	int linen = 0;
	int chara = 0;
	string line;
	ifstream file(filename);
	while (!file.eof())
	{
		getline(file, line); 
		mazeo[linen][chara] = line[chara]; 
		if (line[chara] == 'R')
		{
			this->robots.push_back(Robot(linen,chara,line[chara]));
			robots[0].robotcounter();

		}
		else if (line[chara] == 'H')
		{
			this -> player.setPosition(linen, chara);
		}
		else if (line[chara] == '+')
		{
			this -> posts.push_back(Post(linen,chara,'+'));
		}
		else if (line[chara] == '*')
		{
			this -> posts.push_back(Post(linen, chara, '+'));
		}
		else if (line[chara] == 'O')
		{
			this->expos.row = linen;
			this->expos.col = chara;
			this ->exits.push_back(expos);
			i++;
		}
		cout << mazeo[linen] << endl; 
		chara++;
		linen++;
	}
	file.close();
}

bool Game::play()
{
	while (player.isAlive())
	{
		Movement delta;
		char move;
		string text = "YOU DIED! GAME OVER";
		char moves[9] = { 'Q','W','E','A','S','D','Z','X','C' };
		this->showGameDisplay();
		cout << "What will be your move?";
		cin >> move;
		move = toupper(move);
		string in = find(begin(moves), end(moves), move);
		// move in y? (deltaX due to coordinate system)
		if (in != end(moves))
		{
			if (move == 'Q' || move == 'W' || move == 'E')
				delta.dRow = -1;

			else if (move == 'Z' || move == 'X' || move == 'C')
				delta.dRow = 1;

			// move in x? (deltaY due to coordinate system)
			if (move == 'Q' || move == 'A' || move == 'Z')
				delta.dCol = -1;

			else if (move == 'E' || move == 'D' || move == 'C')
				delta.dCol = 1;
			
			this->player.move(delta);
			if (isValid())
			{
				for (int i = 0; i < exits.size(); i++)
				{
					if (this->player.getRow() == this->exits[i].row)
					{
						if (this->player.getCol() == this->exits[i].col)
						{
							//win
							break;
						}
					}
				}
				if (this->robots.size() > 0)
				{
					this->moveRobots();
				}
				else if (!this->player.isAlive())
				{
					for (int i = 0; i < text.length(); i++)
					{
						cout << text[i];
					}
				}
				else
				{
					continue;
				}
			}
			else if(this->player.isAlive())
			{
				delta.dRow = 0 - (delta.dRow);
				delta.dCol= 0 - (delta.dCol);
				this->player.move(delta);
				continue;
			}
			else
			{
				for (int i = 0; i < text.length(); i++)
				{
					cout << text[i];
				}
			}
		}
	}
	return false;
}

bool Game::isValid()
{
	for (int i = 0; i < posts.size(); i++)
	{
		if (this->player.getRow() == this->posts[i].getRow())
		{
			if (this->player.getCol() == this->posts[i].getCol())
			{
				if (this->posts[i].isElectrified())
				{
					this->player.setAsDead();
					return false;
				}
				else
				{
					return false;
					cout << "You hit hard on a post, move to another position!UwU" << endl;
				}
			}
		}
		else
		{
			for (int i = 0; i < robots.size(); i++)
			{
				if (this->player.getRow() == this->robots[i].getRow())
				{
					if (this->player.getCol() == this->robots[i].getCol())
					{
						this->player.isAlive();
						return false;
					}
				}
				else 
				{
					return true;
				}
			}
		}
	}
}

void Game::showGameDisplay() const
{
	for (int i = 0; i < mazeo.size(); i++)
	{
		cout << mazeo[i] << endl;
	}
}

void Game::moveRobots() {

	int plx = this->player.getRow();
	int ply = this->player.getCol();

	for (int i = 0; i < this->robots.size(); i++) {

		// calcular new X e new Y?
		int newX = plx - this->robots[i].getRow();
		int newY = ply - this->robots[i].getCol();

		// normalize to 1
		int norma = sqrt(newX ^ 2 + newY ^ 2);
		newX = newX * (1/norma) ;
		newY = newY * (1/norma);
		for (int j = 0; j < this->exits.size(); j++)
		{
			if (newX == this->exits[j].row)
			{
				if (newY == this->exits[j].col)
				{
					this->robots[i].setAsDead(i);
					this->robots.erase(robots.begin() + i - 1);
				}
			}
			else
			{
				robots[i].setPosition(newX, newY);
			}
		}
		for (int k = 0; k < posts.size(); k++)
		{
			if (newX == this->posts[k].getRow())
			{
				if (newY == this->posts[k].getCol())
				{
					this->robots[i].setAsDead(i);
					this->robots.erase(robots.begin() + i - 1);
				}
			}
			else
			{
				robots[i].setPosition(newX, newY);
			}
		}
		for (int l = 0; l < robots.size(); l++)
		{
			if (l != i)
			{
				if (newX == this->robots[l].getRow())
				{
					if (newY == this->robots[l].getCol())
					{
						this->robots[i].setAsDead(i);
						this->robots.erase(robots.begin() + i - 1);
						this->robots.erase(robots.begin() + l - 1);
					}
				}
				else
				{
					robots[i].setPosition(newX, newY);
				}
			}

		}
		if (newX == this->player.getRow())
		{
			if (newY == this->player.getCol())
			{
				this->player.setAsDead();
			}
		}
		else
		{
			robots[i].setPosition(newX, newY);
		}
	}
}

void Game::winners()
{

}