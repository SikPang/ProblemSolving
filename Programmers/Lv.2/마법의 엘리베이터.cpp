#include <string>

using namespace std;

void goUp(int* answer, int* storey, char cur, int digit)
{
	*answer += (10 - (cur - '0'));
	*storey += (10 - (cur - '0')) * digit;
}

void goDown(int* answer, int* storey, char cur, int digit)
{
	*answer += (cur - '0');
	*storey -= (cur - '0') * digit;
}

int solution(int storey) {
    int answer = 0;
	std::string str = to_string(storey);
	int digit = 1;

	for (int i = str.length() - 1; i >= 0; --i)
	{
		int prevLen = str.length();

		if (str[i] < '5')
			goDown(&answer, &storey, str[i], digit);
		else if (str[i] > '5')
			goUp(&answer, &storey, str[i], digit);
		else
		{
			int j = i;
			while (j >= 0 && str[j] == '5')
				--j;
			if (j < 0)
				j = 0;
			
			if (i == 0 || str[j] < '5')
				goDown(&answer, &storey, str[i], digit);
			else if (str[j] >= '5')
				goUp(&answer, &storey, str[i], digit);
		}

		str = to_string(storey);
		if (prevLen < str.length())
			++i;
		digit *= 10;
	}

    return answer;
}