#include <vector>

using namespace std;

int solution(int n, int m, vector<int> section) {
    int answer = 0;
	int reach = 0;

	for (int i = 0; i < section.size(); ++i)
	{
		if (reach <= section[i])
		{
			reach = section[i] + m;
			++answer;
		}
	}

    return answer;
}