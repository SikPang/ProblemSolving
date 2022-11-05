#include <string>
#include <vector>
using namespace std;

bool IsSubString(string src, int index, string target)
{
    for (int i = 0; i < target.size(); ++i)
    {
        if (src[index] != target[i])
            return false;
        ++index;
    }
    return true;
}

int solution(vector<string> babbling)
{
    string ongal[4] = {"aya", "ye", "woo", "ma"};
    int answer = 0;
    bool isPossible;
    int duplicate;

    for (int i = 0; i < babbling.size(); ++i)
    {
        isPossible = false;
        for (int j = 0; j < babbling[i].size(); ++j)
        {
            duplicate = 5;
            for (int k = 0; k < 4; ++k)
            {
                if (k == duplicate) continue;
                if (IsSubString(babbling[i], j, ongal[k]))
                {
                    j += ongal[k].size();
                    duplicate = k;
                    k = -1;
                    if (j == babbling[i].size()) 
                    {
                        isPossible = true;
                        break;
                    }
                }
            }
            if (!isPossible) break;
        }
        if (isPossible) ++answer;
    }

    return answer;
}