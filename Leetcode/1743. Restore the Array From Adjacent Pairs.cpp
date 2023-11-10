class Solution {
private:
    struct Value
    {
        vector<int> nodes;
        bool isVisited;
        Value() : nodes(),isVisited(0) {}
    };

    void dfs(unordered_map<int, Value>& map, unordered_map<int, Value>::iterator cur, deque<int>& answer, int depth, bool isLeft)
    {
        isLeft ? answer.push_front(cur->first) : answer.push_back(cur->first);
        cur->second.isVisited = true;

        for (int i=0; i<cur->second.nodes.size(); ++i)
        {
            if (depth == 0 && i == 0)
                isLeft = true;
            else if (depth == 0 && i == 1)
                isLeft = false;

            auto iter = map.find(cur->second.nodes[i]);
            if (iter != map.end() && !iter->second.isVisited)
                dfs(map, iter, answer, depth+1, isLeft);
        }
    }

public:
    vector<int> restoreArray(vector<vector<int>>& adjacentPairs)
    {
        unordered_map<int, Value> map;
        deque<int> answer;

        for (int i=0; i<adjacentPairs.size(); ++i)
        {
            map[adjacentPairs[i][0]].nodes.push_back(adjacentPairs[i][1]);
            map[adjacentPairs[i][1]].nodes.push_back(adjacentPairs[i][0]); 
        }

        dfs(map, map.begin(), answer, 0, true);
        
        return vector<int>(answer.begin(), answer.end());
    }
};