#include <string>
#include <vector>
#include <limits.h>
using namespace std;

int answer = INT_MAX;

bool isConvertable(string& cur, string& target)
{
    int diffCnt = 0;
    
    for (int i=0; i<cur.length(); ++i)
    {
        if (cur[i] != target[i])
            ++diffCnt;
        if (diffCnt > 1)
            return false;
    }
    if (diffCnt == 1)
        return true;
    return false;
}

void dfs(vector<string>& words, vector<bool>& isUsed, string& target, string& cur, int depth)
{
    if (cur == target)
    {
        if (answer > depth)
            answer = depth;
        return;
    }
    
    for (int i=0; i<words.size(); ++i)
    {
        if (!isUsed[i] && isConvertable(cur, words[i]))
        {
            isUsed[i] = true;
            dfs(words, isUsed, target, words[i], depth + 1);
            isUsed[i] = false;
        }
    }
}

int solution(string begin, string target, vector<string> words) {
    vector<bool> isUsed(words.size());
    string cur = begin;

    dfs(words, isUsed, target, cur, 0);
    if (answer == INT_MAX)
        answer = 0;
    return answer;
}