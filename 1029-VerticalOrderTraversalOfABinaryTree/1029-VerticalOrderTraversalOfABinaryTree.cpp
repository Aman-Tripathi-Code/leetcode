// Last updated: 1/11/2026, 1:00:48 PM
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
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>> mp;
        queue<pair<TreeNode*,pair<int,int>>> q;
        q.push({root,{0,0}});
        while(!q.empty()){
            auto node = q.front();
            q.pop();
            int x = node.second.first, y = node.second.second ;
            TreeNode* z = node.first;
            mp[x][y].insert(z->val);
            if(z->left){
                q.push({z->left,{x-1,y+1}});
            }
            if(z->right){
                q.push({z->right,{x+1,y+1}});
            }
        }
        vector<vector<int>> ans;
        for(auto p:mp){
            vector<int> col;
            for(auto q:p.second){
                col.insert(col.end(),q.second.begin(),q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};