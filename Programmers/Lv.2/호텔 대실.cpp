#include <string>
#include <vector>
#include <algorithm>
#define END_TIME 1
#define START_TIME 0

using namespace std;

void increaseTenMinutes(string& time)
{
	if (time[3] == '5')
	{
		if (time[1] == '9')
		{
			++time[0];
			time[1] = '0';
		}
		else
			++time[1];
		time[3] = '0';
	}
	else
		++time[3];
}

int solution(vector<vector<string>> book_time) {
	vector<string> timeTable;

	sort(book_time.begin(), book_time.end());

	for (int i = 0; i < book_time.size(); ++i)
	{
		bool isPushed = false;
		increaseTenMinutes(book_time[i][END_TIME]);

		for (int j = 0; j < timeTable.size(); ++j)
		{
			if (timeTable[j] <= book_time[i][START_TIME])
			{
				timeTable[j] = book_time[i][END_TIME];
				isPushed = true;
				break;
			}
		}
		if (!isPushed)
			timeTable.push_back(book_time[i][END_TIME]);
	}

    return timeTable.size();
}