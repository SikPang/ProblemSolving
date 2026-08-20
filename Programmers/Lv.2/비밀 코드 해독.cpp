#include <string>
#include <vector>
#include <utility>
#include <set>
#include <algorithm>

using namespace std;

void GetCombination(vector<vector<int>>& combinations, vector<int>& candidates, vector<int>& buffer, int count, int idx, int depth){
    if (depth == count){
        combinations.push_back(buffer);
        return;
    }
    
    for (int i=idx; i<candidates.size(); ++i){
        buffer[depth] = candidates[i];
        GetCombination(combinations, candidates, buffer, count, i+1, depth+1);
    }
}

void recur(set<vector<int>>& ret, vector<vector<int>>& q, vector<int>& ans, vector<int>& usedCount, int depth){
    if (depth == q.size()) {
        vector<int> selected;
        vector<int> candidates;

        for (int i = 1; i < usedCount.size(); ++i) {
            if (usedCount[i] > 0) {
                selected.push_back(i);
            } else if (usedCount[i] == 0) {
                candidates.push_back(i);
            }
        }

        int choiceCount = 5 - selected.size();

        if (choiceCount < 0 || choiceCount > candidates.size()) {
            return;
        }

        vector<vector<int>> combinations;
        vector<int> buffer(choiceCount);

        GetCombination(combinations, candidates, buffer, choiceCount, 0, 0);

        for (int i = 0; i < combinations.size(); ++i) {
            vector<int> temp = selected;

            for (int j = 0; j < combinations[i].size(); ++j) {
                temp.push_back(combinations[i][j]);
            }

            sort(temp.begin(), temp.end());
            ret.insert(temp);
        }

        return;
    }

    vector<int> candidates;
    int selectedCount = 0;

    for (int i = 0; i < 5; ++i) {
        int node = q[depth][i];

        if (usedCount[node] > 0) {
            ++selectedCount;
        } else if (usedCount[node] == 0) {
            candidates.push_back(node);
        }
    }

    int choiceCount = ans[depth] - selectedCount;
    
    if (choiceCount < 0) return;
    
    vector<vector<int>> combinations;
    vector<int> buffer(choiceCount);

    GetCombination(combinations, candidates, buffer, choiceCount, 0, 0);
    
    for (int i = 0; i < combinations.size(); ++i) {
        for (int j = 0; j < combinations[i].size(); ++j) {
            ++usedCount[combinations[i][j]];
        }

        vector<int> blocked;

        for (int j = 0; j < 5; ++j) {
            int node = q[depth][j];

            if (usedCount[node] <= 0) {
                --usedCount[node];
                blocked.push_back(node);
            }
        }

        recur(ret, q, ans, usedCount, depth + 1);

        for (int node : blocked) {
            ++usedCount[node];
        }

        for (int j = 0; j < combinations[i].size(); ++j) {
            --usedCount[combinations[i][j]];
        }
    }
}

int solution(int n, vector<vector<int>> q, vector<int> ans) {
    for (int i=0; i<q.size()-1; ++i){
        for (int j=i+1; j<q.size(); ++j){
            if (ans[i] < ans[j]){
                swap(ans[i], ans[j]);
                swap(q[i], q[j]);
            }
        }
    }

    set<vector<int>> ret;
    vector<int> usedCount(n+1);
    recur(ret, q, ans, usedCount, 0);
    return ret.size();
}