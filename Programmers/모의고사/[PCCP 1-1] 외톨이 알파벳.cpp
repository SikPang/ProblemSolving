#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

string solution(string input_string)
{
    unordered_map<char, bool> map;
    vector<char> alone;
    string answer = "";
    int arr[27] = {};

    for (int i = 0; i < input_string.size(); ++i)
    {
        if (arr[input_string[i] - 'a'] == 0)
            ++arr[input_string[i] - 'a'];
        else
        {
            if (input_string[i - 1] != input_string[i] && map.find(input_string[i]) == map.end())
            {
                alone.push_back(input_string[i]);
                map.insert(make_pair(input_string[i], true));
            }
            else
                ++arr[input_string[i] - 'a'];
        }
    }

    if (alone.size() == 0)
        return "N";
    else
    {
        sort(alone.begin(), alone.end());
        for (int i = 0; i < alone.size(); ++i)
            answer += alone[i];
        return answer;
    }
}