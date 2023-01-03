#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<string> solution(vector<string> record) 
{
	vector<string> answer;
	unordered_map<string, string> map;

	for (int i = 0; i < record.size(); ++i)
	{
		if (record[i][0] == 'L') continue;

		for (int j = 0; j < record[i].size(); ++j)
		{
			string uid;
			string name;

			// 유저아이디 뽑기
			if (record[i][j] == ' ')
			{
				++j;
				while (record[i][j] != ' ')
				{
					uid += record[i][j];
					++j;
				}

				// 닉네임 뽑기
				++j;
				while (j < record[i].size())
				{
					name += record[i][j];
					++j;
				}

				if (map.find(uid) == map.end())
					map.insert(make_pair(uid, name));
				else
					map[uid] = name;
			}
		}
	}

	for (int i = 0; i < record.size(); ++i)
	{
		if (record[i][0] == 'C') continue;

		for (int j = 0; j < record[i].size(); ++j)
		{
			string uid;
			string comment;

			// 유저아이디 뽑기
			if (record[i][j] == ' ')
			{
				++j;
				while (j < record[i].size() && record[i][j] != ' ')
				{
					uid += record[i][j];
					++j;
				}

				// 메시지 추가
				comment += map[uid];
				if (record[i][0] == 'E')
					comment += "님이 들어왔습니다.";
				else
					comment += "님이 나갔습니다.";

				answer.push_back(comment);
				break;
			}
		}
	}

	return answer;
}