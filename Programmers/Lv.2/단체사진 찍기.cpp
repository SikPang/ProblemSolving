#include <algorithm>
#include <string>
#include <vector>
#include <math.h>
#define CH_SIZE 8

using namespace std;

const char characters[CH_SIZE] = {'A', 'C', 'F', 'J', 'M', 'N', 'R', 'T'};

bool isCorrect(vector<string>& data, string& buf)
{
	for (int i=0; i<data.size(); ++i)
	{
		char from = data[i][0];
		char to = data[i][2];
		int dist = data[i][4] - '0';
		int gap = abs(find(buf.begin(), buf.end(), from) - find(buf.begin(), buf.end(), to)) - 1;

		if ((data[i][3] == '<' && gap >= dist)
			|| (data[i][3] == '>' && gap <= dist)
			|| (data[i][3] == '=' && gap != dist))
			return false;
	}
	return true;
}

void get_permutation(vector<string>& data, vector<string>& table, vector<bool>& isUsed, string& buf, int depth)
{
	if (depth == CH_SIZE)
	{
		if (isCorrect(data, buf))
			table.push_back(buf);
		return;
	}

	for (int i=0; i<CH_SIZE; ++i)
	{
		if (isUsed[i])
			continue;
		
		isUsed[i] = true;
		buf[depth] = characters[i];
		get_permutation(data, table, isUsed, buf, depth+1);
		isUsed[i] = false;
	}
}

int solution(int n, vector<string> data) {
    vector<string> table;
	vector<bool> isUsed(CH_SIZE);
	string buf;

	table.reserve(CH_SIZE * CH_SIZE);
	buf.resize(CH_SIZE);
	get_permutation(data, table, isUsed, buf, 0);

    return table.size();
}