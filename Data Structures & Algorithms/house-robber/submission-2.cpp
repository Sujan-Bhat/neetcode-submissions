class Solution {
public:
    int rob(vector<int>& nums) {
        //tabulation - memory optimization
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        int res;

        for(int i = 2; i < n; i++){
            res = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = res;
        }

        return res;
    }
};