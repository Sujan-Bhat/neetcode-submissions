class Solution {
public:
    int helper(vector<int>& cost, int idx, vector<int>& memo){

        if(idx == 1 || idx == 0) return cost[idx];

        if(memo[idx] != -1){
            return memo[idx];
        }

        int p1 = helper(cost, idx - 1, memo) + cost[idx];
        int p2 = helper(cost, idx - 2, memo) + cost[idx];

        return memo[idx] = min(p1, p2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        vector<int> memo(n, -1);
        int p1 = helper(cost, n - 1, memo);
        int p2 = helper(cost, n - 2, memo);

        return min(p1, p2);
    }
};
