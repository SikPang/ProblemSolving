#include <string>
#include <vector>
#include <set>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;

vector<vector<int>> candidateKeys;

int answer = 0;

bool isMinimal(vector<int>& target)
{
    for (int i=0; i<candidateKeys.size(); ++i)
    {
        int size = 0;
        for (int j=0; j<candidateKeys[i].size(); ++j)
        {
            if (find(target.begin(), target.end(), candidateKeys[i][j]) != target.end())
                ++size;
        }
        if (size == candidateKeys[i].size())
            return false;
    }
    return true;
}

bool isUnique(vector<vector<string>>& relation, vector<int>& buf)
{
    if (!isMinimal(buf))
        return false;
    
    set<vector<string>> dupChecker;
    vector<vector<string>> target(relation.size());
    
    for (int i=0; i<buf.size(); ++i)
    {
        for (int j=0; j<relation.size(); ++j)
            target[j].push_back(relation[j][buf[i]]);
    }
    
    for (int i=0; i<relation.size(); ++i)
        dupChecker.insert(target[i]);
    
    if (dupChecker.size() == target.size())
        return true;
    return false;
}

void dfs(vector<vector<string>>& relation, vector<int>& buf, vector<bool>& isUsed, int max, int depth, int idx)
{
    if (depth == max && isUnique(relation, buf))
    {
        candidateKeys.push_back(buf);
        ++answer;
        return;
    }
    
    for (int i=idx; i<relation[0].size(); ++i)
    {
        if (isUsed[i])
            continue;
        
        isUsed[i] = true;
        buf.push_back(i);
        dfs(relation, buf, isUsed, max, depth+1, i+1);
        isUsed[i] = false;
        buf.pop_back();
    }
}

int solution(vector<vector<string>> relation) 
{
    vector<bool> isUsed(relation[0].size());
    
    for (int i=0; i<relation[0].size(); ++i)
    {
        vector<int> cur{i};
        if (isUnique(relation, cur))
		{
            isUsed[i] = true;
			++answer;
		}
    }
    
    vector<int> buf;
    for(int maxDepth=2; maxDepth<=relation[0].size(); ++maxDepth)
        dfs(relation, buf, isUsed, maxDepth, 0, 0);
    
	return answer;
}