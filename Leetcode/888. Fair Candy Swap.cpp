class Solution {
public:
    vector<int> fairCandySwap(vector<int>& aliceSizes, vector<int>& bobSizes) {
        int aliceSum = accumulate(aliceSizes.begin(), aliceSizes.end(), 0);
        int bobSum = accumulate(bobSizes.begin(), bobSizes.end(), 0);
        int gap = aliceSum - bobSum;

        bool isAliceBigger = gap > 0;
        vector<int>& bigger = isAliceBigger ? aliceSizes : bobSizes;
        vector<int>& smaller = isAliceBigger ? bobSizes : aliceSizes;

        sort(bigger.begin(), bigger.end());
        sort(smaller.begin(), smaller.end());
        gap = abs(gap);

        for (int i=0; i<bigger.size(); ++i){
            for (int j=0; j<smaller.size(); ++j){
                if (bigger[i] - smaller[j] == gap/2){
                    return isAliceBigger ? vector<int>{bigger[i], smaller[j]} : vector<int>{smaller[j], bigger[i]};
                }
            }
        }
        return vector<int>{0, 0};
    }
};