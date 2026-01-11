class Solution {
public:
    bool isPowerOfThree(int n) {
        long cur = 1;

        while (cur < n){
            cur *= 3;
        }
        return cur == n;
    }
};