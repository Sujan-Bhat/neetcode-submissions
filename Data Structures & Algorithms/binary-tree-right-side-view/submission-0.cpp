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
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr) return {};

        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);

        int prevVal = root->val;
        vector<int> ans;
        

        while(q.size() > 0){
            TreeNode* cur = q.front();
            q.pop();

            if(cur == nullptr){
                ans.push_back(prevVal);
                if(!q.empty())q.push(nullptr);
                continue;
            }
            if(cur->left != nullptr){
                q.push(cur->left);
            }
            if(cur->right != nullptr){
                q.push(cur->right);
            }
            prevVal = cur->val;
        }
        return ans;
    }
};
