class Solution {
struct Info {
    int num;
    int distance;
    Info(int num, int distance) : num(num), distance(distance) {}
    bool operator>(const Info& other) const {
        return distance > other.distance;
    }
};

public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<Info, vector<Info>, greater<Info>> pq;
        vector<int> table(n + 1, INT_MAX);

        unordered_map<int, vector<Info>> graph;
        for (int i=0; i<times.size(); ++i){
            graph[times[i][0]].push_back(Info(times[i][1], times[i][2]));
        }

        pq.push(Info(k, 0));
        table[k] = 0;

        while (!pq.empty()){
            Info cur = pq.top();
            pq.pop();

            if (cur.distance != table[cur.num]) continue;

            vector<Info>& nextList = graph[cur.num];
            for (int i=0; i<nextList.size(); ++i){
                Info next = nextList[i];
                if (table[next.num] <= cur.distance + next.distance) continue;

                table[next.num] = cur.distance + next.distance;
                next.distance += cur.distance;

                pq.push(next);
            }
        }

        int maxNum = -1;
        for (int i=1; i<n+1; ++i){
            if (table[i] == INT_MAX) return -1;
            maxNum = max(table[i], maxNum);
        }
        return maxNum;
    }
};