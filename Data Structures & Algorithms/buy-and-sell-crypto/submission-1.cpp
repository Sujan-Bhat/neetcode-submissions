class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mProfit = 0;
    
        int low = 0;
        int high = 1;

        while(high < prices.size()){
            if(prices[low] < prices[high]){
                int profit = prices[high] - prices[low];
                mProfit = max(profit, mProfit);
            } else{
                low = high;
            }
            high++;
        }

        return mProfit;
    }
};
