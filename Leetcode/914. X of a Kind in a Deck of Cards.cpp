class Solution {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        unordered_map<int, int> map;

        for (int n : deck) {
            ++map[n];
        }

        int result = map.begin()->second;
        for (const auto& item : map) {
            result = gcd(result, item.second);
        }
        return result > 1;
    }
};