class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set<int> uniqueCandies(candyType.begin(), candyType.end());
        int maxCount = candyType.size() / 2.0f;
        return std::min(maxCount, (int)uniqueCandies.size());
    }
};