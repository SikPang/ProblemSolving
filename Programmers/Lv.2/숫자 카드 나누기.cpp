#include <algorithm>
#include <vector>

using namespace std;

int getGCD(int big, int small)
{
	int mod = big % small;

	if (mod == 0)
		return small;

	return getGCD(small, mod);
}

int getAnswer(vector<int>& main, vector<int>& target)
{
	int gcd = main.front();

	for (int i = 0; i + 1 < main.size(); ++i)
		gcd = getGCD(gcd, main[i + 1]);

	bool isDivided = false;
	for (int i = 0; i < target.size(); ++i)
	{
		if (target[i] % gcd == 0)
		{
			isDivided = true;
			break;
		}
	}
	
	if (isDivided)
		return 0;
	else
		return gcd;
}

int solution(vector<int> arrayA, vector<int> arrayB) {
	int answerA = getAnswer(arrayA, arrayB);
	int answerB = getAnswer(arrayB, arrayA);
	
	return max(answerA, answerB);
}