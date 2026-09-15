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
    pair<int, bool> helper(TreeNode* root){
        if(root == nullptr) return {0, true};
        
        pair<int, bool> left = helper(root->left);
        pair<int, bool> right = helper(root->right);

        if(left.second && right.second){
            if(abs(left.first - right.first) <= 1){
                return {max(left.first, right.first) + 1 ,true};
            }
        }
        return {max(left.first, right.first) + 1 ,false};

    }

    bool isBalanced(TreeNode* root) {
       if(root == nullptr) return true;
       pair<int, bool> ans = helper(root);

       return ans.second;
    }
};
