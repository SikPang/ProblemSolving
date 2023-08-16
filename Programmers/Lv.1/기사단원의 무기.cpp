using namespace std;

int solution(int number, int limit, int power) {
    int answer = 1;

	for (int i = 2; i <= number; ++i)
	{
		int num = 1;
		int isSquareRoot = 0;

		for (int j = 2; j * j <= i; ++j)
		{
			if (j * j == i)
				isSquareRoot = 1;
			else if (i % j == 0)
				++num;
		}
		num = num * 2 + isSquareRoot;

		if (num > limit)
			answer += power;
		else
			answer += num;
	}

    return answer;
}