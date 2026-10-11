class Solution {
public:
    int helper(vector<int>& nums, int start, int end){

        if((end - start) == 1) return nums[start];
        if((end - start) == 2) return max(nums[start], nums[end]);

        int prev1 = nums[start];
        int prev2 = max(nums[start], nums[start+1]);

        int res;

        for(int i = start + 2; i < end; i++){
            res = max(nums[i] + prev1, prev2);
            prev1 = prev2;
            prev2 = res;
        }
        return res;
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) return nums[0];
        if(n == 2) return max(nums[0], nums[1]);

        int max1 = helper(nums, 0, n -1);
        int max2 = helper(nums, 1, n);

        return max(max1, max2);

        
    }
};