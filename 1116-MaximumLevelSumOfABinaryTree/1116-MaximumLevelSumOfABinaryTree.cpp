// Last updated: 1/11/2026, 1:00:39 PM
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
    int maxLevelSum(TreeNode* root) {
        int maxi = -1e9, lvl = 1, ans = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int sz = q.size();
            int lvlSum = 0;
            for(int i = 0; i<sz; i++){
                TreeNode* node = q.front();
                q.pop();
                lvlSum += node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if(lvlSum > maxi){
                ans = lvl;
                maxi = lvlSum;
            }
            lvl++;
        }
        return ans;
    }
};