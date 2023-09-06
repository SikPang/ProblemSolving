#include <iostream>
#include <string>
#include <vector>
#define GOORM 1
#define PLAYER 2
using namespace std;

struct Player
{
	int score;
	int posY;
	int posX;
	int id;
	inline void setPos(int y, int x){posY = y; posX = x;}
};

struct Tile
{
	int dist;
	int dirX;
	int value;
	int dirY;
};

void play(vector< vector<Tile> >& board, Player& player)
{
	board[player.posY][player.posX].value = player.id;
	++player.score;

	while (true)
	{
		int dist = board[player.posY][player.posX].dist;
		int dirY = board[player.posY][player.posX].dirY;
		int dirX = board[player.posY][player.posX].dirX;

		for (int i=0; i<dist; ++i)
		{
			int nextY = player.posY + dirY;
			int nextX = player.posX + dirX;

			if (nextY < 0)
				nextY = board.size() - 1;
			if (nextX < 0)
				nextX = board.size() - 1;
			nextY %= board.size();
			nextX %= board.size();

			if (board[nextY][nextX].value == player.id)
				return;

			player.setPos(nextY, nextX);
			++player.score;
			board[nextY][nextX].value = player.id;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	int num;
	cin >> num;

	vector< vector<Tile> > board(num);
	for (int i=0; i<num; ++i)
		board[i].resize(num);

	Player goorm = {};
	goorm.id = GOORM;

	Player player = {};
	player.id = PLAYER;

	int goormY, goormX, playerY, playerX;
	cin >> goormY >> goormX >> playerY >> playerX;
	goorm.setPos(goormY - 1, goormX - 1);
	player.setPos(playerY - 1, playerX - 1);

	const int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

	for (int i=0; i<num; ++i)
	{
		for (int j=0; j<num; ++j)
		{
			string input;
			cin >> input;

			int idx;
			if (input.back() == 'U')
				idx = 0;
			else if (input.back() == 'R')
				idx = 1;
			else if (input.back() == 'D')
				idx = 2;
			else if (input.back() == 'L')
				idx = 3;

			board[i][j].dirY = dir[idx][0];
			board[i][j].dirX = dir[idx][1];
			board[i][j].dist = stoi(input.substr(0, input.length() - 1));
		}
	}
	
	play(board, goorm);
	play(board, player);

	if (player.score > goorm.score)
		cout << "player " << player.score << "\n";
	else
		cout << "goorm " << goorm.score << "\n";
}