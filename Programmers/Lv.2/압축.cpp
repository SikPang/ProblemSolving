vector<int> solution(string msg)
{
	vector<int> answer;
	unordered_map<string, int> map;
	int max_length = 1;
	int map_size = 26;
	string c = "A";

	for (int i = 0; i < 26; ++i)
	{
		map.insert(make_pair(c, i + 1));
		++c[0];
	}

	for (int i = 0; i < msg.size(); ++i)
	{
		int j = i;
		string temp;
		string prev;

		while (j < msg.size() && j < max_length + i)
		{
			temp += msg[j];
			++j;
		}

		while (map.find(temp) == map.end())
		{
			prev = temp;
			temp.erase(temp.size() - 1);
		}
		answer.push_back(map[temp]);

		if (!prev.empty())
			map.insert(make_pair(prev, map_size + 1));
		else
		{
			if (max_length + i < msg.size())
			{
				prev += temp;
				prev += msg[max_length + i];
			}
			map.insert(make_pair(prev, map_size + 1));
		}
		if (max_length < prev.size())
			max_length = prev.size();
		i += temp.size() - 1;
		++map_size;
	}

	return answer;
}