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
private:
    int heightOfTree(TreeNode* root){
        if(root == nullptr) return 0;
        return (max(heightOfTree(root->left), heightOfTree(root->right))+1);
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0;
        
        int leftDia = diameterOfBinaryTree(root->left);
        int rightDia = diameterOfBinaryTree(root->right);
        int currDia = heightOfTree(root->left) + heightOfTree(root->right);

        return max(currDia, max(leftDia,rightDia));
    }
};
