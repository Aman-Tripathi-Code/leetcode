// Last updated: 1/11/2026, 12:59:39 PM
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
    int amountOfTime(TreeNode* root, int start) {
        if(!root){
            return 0;
        }
        unordered_map<TreeNode*,TreeNode*> par;
        unordered_map<TreeNode*,bool> vis;
        par[root] = NULL;
        TreeNode* target = NULL;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                TreeNode* node = q.front();
                q.pop();
                vis[node] = false;
                if(node->val == start){
                    target = node;
                }
                if(node->left){
                    par[node->left] = node;
                    q.push(node->left);
                }
                if(node->right){
                    par[node->right] = node;
                    q.push(node->right);
                }
            }
        }
        q.push(target);
        vis[target] = true;
        int time = 0;
        while(!q.empty()){
            int n = q.size();
            time++;
            while(n--){
                TreeNode* temp = q.front();
                q.pop();
                
                if(temp->left!=NULL && vis[temp->left]==false){
                    q.push(temp->left);
                    vis[temp->left] = true;
                }
                if(temp->right!=NULL && vis[temp->right]==false){
                    q.push(temp->right);
                    vis[temp->right] = true;
                }

                if(par[temp]!=NULL && vis[par[temp]]==false){
                    q.push(par[temp]);
                    vis[par[temp]] = true;
                }
            }
        }
        return time-1;
    }
};