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
    bool isIdentical(TreeNode* r1, TreeNode* r2){
        if(r1 == nullptr || r2 == nullptr) return r1==r2;

        return (isIdentical(r1->left, r2->left) && isIdentical(r1->right,r2->right) && (r1->val == r2->val));
    }

public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr || subRoot == nullptr) return root==subRoot;

        if((root->val == subRoot->val) && isIdentical(root, subRoot)){
            return true ;
        }
        return isSubtree(root->left, subRoot) || isSubtree(root->right, subRoot);
    }
};
