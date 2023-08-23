#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
	int left = 50;
	int right = 0;
	int up = 50;
	int down = 0;

	for (int i=0; i<wallpaper.size(); ++i)
	{
		for (int j=0; j<wallpaper[i].length(); ++j)
		{
			if (wallpaper[i][j] == '.')
				continue;
			
			left = min(left, j);
			right = max(right, j);
			up = min(up, i);
			down = max(down, i);
		}
	}
    return vector<int>{up, left, down + 1, right + 1};
}
