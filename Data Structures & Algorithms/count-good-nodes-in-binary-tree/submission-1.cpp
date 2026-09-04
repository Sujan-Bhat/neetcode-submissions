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
    int helper(TreeNode* root, int maxVal){
        if(root == nullptr) return 0;

        if(root->val > maxVal){
            maxVal = root->val;
        }

        int leftGood = helper(root->left, maxVal);

        int rightGood = helper(root->right, maxVal);

        
        if(root->val < maxVal){
            return leftGood + rightGood;
        }

        return leftGood + rightGood + 1;

    }

    int goodNodes(TreeNode* root) {
        return helper(root, INT_MIN);
    }
};
