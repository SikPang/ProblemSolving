class Solution {
private:
    static bool lenCmp(string& a, string& b)
    {
        return a.length() < b.length();
    }

    void getNextPredecessor(string& origin, string& result, int excludeIdx)
    {
        result.reserve(origin.length() - 1);
        for (int i=0; i<origin.length(); ++i)
        {
            if (i == excludeIdx) continue;
            result += origin[i];
        }
    }

public:
    int longestStrChain(vector<string>& words) 
    {
        sort(words.begin(), words.end(), lenCmp);

        unordered_map<string, int> chains;
        for (int i=0; i<words.size(); ++i)
        {
            int maxChainSize = 0;
            for (int j=0; j<words[i].length(); ++j)
            {
                string predecessor;
                getNextPredecessor(words[i], predecessor, j);

                unordered_map<string, int>::iterator iter = chains.find(predecessor);
                if (iter != chains.end() && iter->second > maxChainSize)
                    maxChainSize = iter->second;
            }
            chains.insert(make_pair(words[i], maxChainSize + 1));
        }
        
        int answer = 0;
        for (unordered_map<string, int>::iterator iter = chains.begin(); iter != chains.end(); ++iter)
        {
            if (iter->second > answer)
                answer = iter->second;
        }
        return answer;
    }
};