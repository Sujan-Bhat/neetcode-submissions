class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;

        //brute force
        for(int i = 0; i < prices.size()-1; i++){
            
            for(int j = i+1; j < prices.size(); j++){
                if((prices[j] - prices[i]) > profit){
                    profit = prices[j] - prices[i];
                }
            }

        }
        return profit;
    }
};
