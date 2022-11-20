#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int arr[100001] = {};

bool compare(pair<int, int> a, pair<int, int> b) 
{
	return a.second > b.second;
}

int MyAtoi(string str)
{
    int num = 0;
    
    for(int i=0; i<str.size(); ++i)
        num = num * 10 + str[i] - '0';
    
    return num;
}

vector<int> solution(string s) 
{
    vector<int> answer;
	vector< pair<int,int> > tempVec;
	string temp;
    int i = 0;
    
	while (s[i] != '\0')
	{
		temp = "";
		while (true)
		{
			if (s[i] < '0' || s[i] > '9') 
			{
				++i;
				break;
			}
			temp += s[i];
			++i;
		}
		if (!temp.empty())
            ++arr[MyAtoi(temp)];
	}

	for (int i=1; i<100001; ++i)
	{
		if (arr[i] > 0)
			tempVec.push_back(make_pair(i, arr[i]));
	}

	sort(tempVec.begin(), tempVec.end(), compare);
	
	for (int i=0; i<tempVec.size(); ++i)
		answer.push_back(tempVec[i].first);

    return answer;
}