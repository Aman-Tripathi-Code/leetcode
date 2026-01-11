// Last updated: 1/11/2026, 1:01:02 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    private:
    void markParent(TreeNode* root, unordered_map<TreeNode*,TreeNode*> &par, unordered_map<TreeNode*,bool> &vis){
        if(!root) return;
        par[root] = NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                vis[node] = false;
                if(node->left){
                    q.push(node->left);
                    par[node->left] = node;
                }
                if(node->right){
                    q.push(node->right);
                    par[node->right] = node;
                }
            }
        }
    }
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> par;
        unordered_map<TreeNode*,bool> vis;

        markParent(root,par,vis);

        queue<TreeNode*> q;
        q.push(target);

        vis[target] = true;

        while(!q.empty()){
            int sz = q.size();
            if(k-- == 0) break;
            while(sz--){
                TreeNode* node = q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    q.push(node->left);
                    vis[node->left] = true;
                }

                if(node->right && !vis[node->right]){
                    q.push(node->right);
                    vis[node->right] = true;
                }

                if(par[node] && !vis[par[node]]){
                    q.push(par[node]);
                    vis[par[node]] = true;
                }
            }
        }
        vector<int> ans;
        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            ans.push_back(node->val);
        }
        return ans;
    }
};