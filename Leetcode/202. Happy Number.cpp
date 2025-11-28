class Solution {
private:
    int GetNextNumber(int cur){
        int ret = 0;
        while (cur > 0){
            int remainder = cur % 10;
            ret += remainder * remainder;
            cur /= 10;
        }
        return ret;
    }

public:
    bool isHappy(int n) {
        unordered_set<int> dupChecker;
        int nextNum = n;
        while (nextNum > 0){
            nextNum = GetNextNumber(nextNum);
            if (dupChecker.find(nextNum) != dupChecker.end()) return false;

            dupChecker.insert(nextNum);
            if (nextNum == 1) return true;
        }
        return false;
    }
};