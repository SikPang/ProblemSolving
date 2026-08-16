#include <string>
#include <vector>

using namespace std;

bool compare(pair<string, int>* info1, pair<string, int>* info2)
{
	if (info1->first > info2->first)
		return true;
    else if (info1->first == info2->first && info1->second > info2->second)
	    	return true;
    return false;
}

void setting(pair<string, int> *info)
{
	for (int i = 0; i < info->first.size(); ++i)
	{
		if (info->first[i] >= 'A' && info->first[i] <= 'Z')
			info->first[i] += 32;

		if (i > 0 && (info->first[i - 1] < '0' || info->first[i - 1] > '9') 
            && info->first[i] >= '0' && info->first[i] <= '9')
		{
			info->second = stoi(info->first.substr(i, info->first.size() - i), nullptr);
            info->first = info->first.substr(0, i);
			break;
		}
	}
}

vector<string> solution(vector<string> files)
{
	vector< pair<string, int> > answer;

	for (int i = 0; i < files.size(); ++i)
		answer.push_back(make_pair(files[i], 0));

	for (int i = 0; i < answer.size(); ++i)
		setting(&answer[i]);

	for (int j = 0; j < answer.size() - 1; ++j)
	{
		for (int i = 0; i < answer.size() - 1 - j; ++i)
		{
			if (compare(&answer[i], &answer[i+1]))
			{
				pair<string, int> tempp = answer[i];
				answer[i] = answer[i + 1];
				answer[i + 1] = tempp;

				string temps = files[i];
				files[i] = files[i + 1];
				files[i + 1] = temps;
			}
		}
	}

	return files;
}