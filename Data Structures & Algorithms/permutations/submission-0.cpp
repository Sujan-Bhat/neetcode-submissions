class Solution {
public:
    void helper(vector<int>& nums, vector<vector<int>>& ans, int idx, int& n){

        if(idx == n){
            ans.push_back(nums);
            return;
        }

        for(int i = idx; i < n; ++i){
            swap(nums[idx], nums[i]);
            helper(nums, ans, idx+1, n);
            swap(nums[idx],nums[i]);
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        helper(nums, ans, 0, n);

        return ans;
    }
};
