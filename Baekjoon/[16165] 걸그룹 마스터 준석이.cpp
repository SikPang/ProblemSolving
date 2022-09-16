#include <algorithm>
#include <unordered_map>
#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	
	unordered_map<string, vector<string>> teamToMember;
	unordered_map<string, string> memberToTeam;

	int team, quiz;
	cin >> team >> quiz;

	for (int i = 0; i < team; ++i)
	{
		string teamName;
		int num;
		vector<string> tempVec;

		cin >> teamName >> num;

		for (int j = 0; j < num; ++j)
		{
			string memberName;
			cin >> memberName;

			teamToMember[teamName].push_back(memberName);
			memberToTeam[memberName] = teamName;
		}

		sort(teamToMember[teamName].begin(), teamToMember[teamName].end());
	}

	for (int i = 0; i < quiz; ++i)
	{
		string input;
		int quizNum;

		cin >> input >> quizNum;

		if (quizNum == 0)
		{
			for (int i = 0; i < teamToMember[input].size(); ++i)
				cout << teamToMember[input][i] << '\n';
		}
		else
			cout << memberToTeam[input] << '\n';
	}
}