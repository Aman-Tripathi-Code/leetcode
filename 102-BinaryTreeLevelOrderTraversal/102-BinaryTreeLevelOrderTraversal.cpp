// Last updated: 1/11/2026, 1:03:19 PM
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
    vector<vector<int>> level;
    if(root==NULL){
        return level;
    }
    queue<TreeNode*> q;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        vector<int> lvl;
        for(int i = 0; i<sz; i++){
            TreeNode* node = q.front();
            q.pop();
            lvl.push_back(node->val);
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }
        }
        level.push_back(lvl);
    }
    return level;
    }
};