#include <vector>
using namespace std;

int solution(int k, int m, vector<int> score) 
{
	int answer = 0;
	int apple[10] = {};
	int remainder = 0;

	for (int i = 0; i < score.size(); ++i)
		++apple[score[i]];

	for (int i = 9; i >= 0; --i)
	{
		answer += i * m * ((apple[i] + remainder) / m);
		remainder = (apple[i] + remainder) % m;
	}

	return answer;
}