class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> answer(score.size());

        vector<pair<int, int>> scoreIdxPair(score.size());
        for (int i=0; i<score.size(); ++i){
            scoreIdxPair[i] = make_pair(score[i], i);
        }

        sort(scoreIdxPair.begin(), scoreIdxPair.end(), [](const pair<int, int>& a, const pair<int, int>& b) {
            return a.first > b.first;
        });

        for (int i=0; i<scoreIdxPair.size(); ++i){
            int rank = i + 1;
            switch (rank){
                case 1:
                    answer[scoreIdxPair[i].second] = "Gold Medal";
                    break;
                case 2:
                    answer[scoreIdxPair[i].second] = "Silver Medal";
                    break;
                case 3:
                    answer[scoreIdxPair[i].second] = "Bronze Medal";
                    break;
                default:
                    answer[scoreIdxPair[i].second] = to_string(rank);
                    break;
            }
        }
        return answer;
    }
};