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
    int search(vector<int>& inOrder, int l, int r, int ele){
        for(int i = l; i <= r; i++){
            if(inOrder[i] == ele){
                return i;
            }
        }
        return -1;
    }

public:

    TreeNode* buildBinaryTree(vector<int>& preOrder, vector<int>& inOrder, int& preIdx, int left, int right){
        
        if(left > right) return nullptr;

        TreeNode* root =new TreeNode(preOrder[preIdx]);

        int inIdx = search(inOrder, left, right, root->val);
        preIdx++;
        root->left = buildBinaryTree(preOrder, inOrder, preIdx, left, inIdx -1);
        root->right = buildBinaryTree(preOrder, inOrder, preIdx, inIdx+1, right);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int preIdx = 0;
        return buildBinaryTree(preorder, inorder, preIdx, 0, preorder.size()-1);
    }
};
