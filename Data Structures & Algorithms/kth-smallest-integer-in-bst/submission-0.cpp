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
    vector<int> inorder;
    void inorderTravel(TreeNode* root){
        if(root == nullptr) return;
        inorderTravel(root->left);
        inorder.push_back(root->val);
        inorderTravel(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {      
        inorderTravel(root);
        return inorder[k-1];
    }
};
