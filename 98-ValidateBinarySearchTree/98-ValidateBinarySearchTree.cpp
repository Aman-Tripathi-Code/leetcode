// Last updated: 1/11/2026, 1:03:23 PM
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
    bool checkBST(TreeNode* root, long long int max, long long int min){
        if(!root){
            return true;
        }
        if(root->val>=max||root->val<=min){
            return false;
        }
        return checkBST(root->left,root->val,min) && checkBST(root->right,max,root->val);
    }
public:
    bool isValidBST(TreeNode* root) {
        return checkBST(root,(long)INT_MAX+1,(long)INT_MIN-1);
    }
};