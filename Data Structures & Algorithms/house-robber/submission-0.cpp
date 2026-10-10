class Solution {
public:
    // memoization
    int helper(vector<int>& nums, int idx, vector<int>& memo){
        
        if(idx < 0) return 0;
        if(idx == 0) return nums[0];

        if(memo[idx] != -1){
            return memo[idx];
        }

        int acc = nums[idx] + helper(nums, idx - 2, memo);
        int rej = helper(nums, idx - 1, memo);

        return memo[idx] = max(acc, rej);
    }
    int rob(vector<int>& nums) {
        vector<int> memo(nums.size(), -1);
        return helper(nums, nums.size()-1, memo);
    }
};