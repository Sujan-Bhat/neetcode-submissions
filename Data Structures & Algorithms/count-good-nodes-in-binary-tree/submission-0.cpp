/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    int helper(TreeNode* root, vector<int>& nums){
        if(root == nullptr) return 0;

        nums.push_back(root->val);

        int leftGood = helper(root->left, nums);

        int rightGood = helper(root->right, nums);

        nums.pop_back();
        for(int i = 0; i < nums.size(); i++){
            if(nums[i] > root->val){
                return leftGood + rightGood;
            }
        }
        return leftGood + rightGood + 1;

    }

    int goodNodes(TreeNode* root) {
        vector<int> nums;
        return helper(root, nums);
    }
};
