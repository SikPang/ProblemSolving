class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int curMaxProfit = 0;
        int minPrice = 2147483647;

        for (int i=0; i<prices.size()-1; ++i){
            int curPrice = prices[i];
            if (curPrice >= minPrice) continue;
            minPrice = curPrice;

            for (int j=i+1; j<prices.size(); ++j){
                curMaxProfit = max(curMaxProfit, prices[j] - curPrice);
            }
        }
        return curMaxProfit;
    }
};