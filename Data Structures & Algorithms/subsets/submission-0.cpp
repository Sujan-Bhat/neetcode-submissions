class Solution {
public:
    void helper(vector<int>& nums, vector<int>& subset, int idx, vector<vector<int>>& ans){

        if(idx == nums.size()){
            ans.push_back(subset);
            return;
        }

        subset.push_back(nums[idx]);
        helper(nums, subset, idx+1, ans);
        subset.pop_back();
        helper(nums, subset, idx+1, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> subset;
        vector<vector<int>> ans;
        helper(nums,subset,0,ans);

        return ans;
    }
};
