#include <string>
#include <vector>
#include <math.h>
#include <limits.h>

using namespace std;

void Crime(vector<vector<int>>& info, vector<vector<int>>& mem, int& minCount, int n, int m, int a, int b, int depth){
    if (depth == info.size()){
        if (a < n && b < m){
            minCount = min(minCount, a);
        }
        return;
    }
    
    if (mem[depth][b] <= a) return;
    
    mem[depth][b] = a;
    
    if (info[depth][0] + a < n){
        Crime(info, mem, minCount, n, m, info[depth][0] + a, b, depth+1);
    }
    
    if (info[depth][1] + b < m){
        Crime(info, mem, minCount, n, m, a, info[depth][1] + b, depth+1);
    }
}

int solution(vector<vector<int>> info, int n, int m) {
    vector<vector<int>> mem(info.size(), vector<int>(m, INT_MAX));
    int minCount = INT_MAX;
    
    Crime(info, mem, minCount, n, m, 0, 0, 0);
    
    return minCount == INT_MAX ? -1 : minCount;
}