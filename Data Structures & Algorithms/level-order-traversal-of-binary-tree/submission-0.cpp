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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == nullptr) return {};

        vector<vector<int>> ans;

        queue<TreeNode*> q;
        vector<int> level;

        q.push(root);
        q.push(nullptr);

        while(q.size() > 0){
            
            TreeNode* cur = q.front();
            q.pop();

            if(cur == nullptr){
                if(q.empty()){
                    break;
                }
                ans.push_back(level);
                level = {};
                q.push(nullptr);
                continue;
            }

            level.push_back(cur->val);

            if(cur->left != nullptr){
                q.push(cur->left);
            }

            if(cur->right != nullptr){
                q.push(cur->right);
            }
        }
        ans.push_back(level);
        return ans;
    }
};
