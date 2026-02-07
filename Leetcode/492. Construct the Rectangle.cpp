class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<vector<int>> pairs;

        for (int i=1; i*i<=area; ++i){
            if (area % i == 0){
                pairs.push_back(vector<int>{area / i, i});
            }
        }

        return pairs[pairs.size()-1];
    }
};