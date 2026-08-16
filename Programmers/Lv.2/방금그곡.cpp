#include <algorithm>
#include <string>
#include <vector>
#include <sstream>
#include <cstring>
#include <tuple>

using namespace std;

bool compare(const tuple<string, int, int>& a, const tuple<string, int, int>& b)
{
	if (get<1>(a) == get<1>(b))
		return get<2>(a) > get<2>(b);
	return get<1>(a) < get<1>(b);
}

void fixSong(string& song, int playTime)
{
	while (song.length() < playTime)
		song += song;
	song = song.substr(0, playTime);
}

int getPlayTime(string startTimeStr, string endTimeStr)
{
	pair<int, int> startTime(stoi(startTimeStr.substr(0, 2)), stoi(startTimeStr.substr(3, 2)));
	pair<int, int> endTime(stoi(endTimeStr.substr(0, 2)), stoi(endTimeStr.substr(3, 2)));
	pair<int, int> resultTime(endTime.first - startTime.first, endTime.second - startTime.second);

	while (resultTime.first > 0)
	{
		resultTime.second += 60;
		--resultTime.first;
	}
	return resultTime.second;
}

void split(string str, vector<string>& result)
{
	int i = 0;
	stringstream ss(str);
	while (getline(ss, result[i++], ','));
}

void fixSharp(string& str)
{
	for (int i=0; i<str.length(); ++i)
	{
		if (str[i] == '#')
		{
			str[i - 1] = tolower(str[i - 1]);
			str.erase(i, 1);
		}
	}
}

string solution(string m, vector<string> musicinfos) {
	vector<tuple<string, int, int>> list;
	fixSharp(m);
    
	for (int i=0; i<musicinfos.size(); ++i)
	{
		vector<string> vec(4);
		
		split(musicinfos[i], vec);
		int playTime = getPlayTime(vec[0], vec[1]);
		fixSharp(vec[3]);
		fixSong(vec[3], playTime);
		if (vec[3].find(m) != string::npos)
			list.push_back(make_tuple(vec[2], playTime, i));
	}
	if (list.empty())
	    return "(None)";
	sort(list.begin(), list.end(), compare);

	return get<0>(list.back());
}