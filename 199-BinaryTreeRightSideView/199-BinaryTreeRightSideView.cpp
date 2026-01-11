// Last updated: 1/11/2026, 1:02:34 PM
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
    void findRightView(TreeNode* root, int level , vector<int>&ds){
        if(!root){
            return;
        }
        if(level==ds.size()){
            ds.push_back(root->val);
        }
        findRightView(root->right,level+1,ds);
        findRightView(root->left,level+1,ds);
    }
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ds;
        int lvl = 0;
        findRightView(root,lvl,ds);
        return ds;
    }
};