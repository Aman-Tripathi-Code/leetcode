// Last updated: 1/11/2026, 1:02:21 PM
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
    TreeNode* recursion(TreeNode* root){
        if(root==NULL){
            return NULL;
        }
        TreeNode* node = new TreeNode(root->val);
        node->left = recursion(root->right);
        node->right = recursion(root->left);
        return node;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        if(!root){
            return NULL;
        }
        return recursion(root);
    }
};