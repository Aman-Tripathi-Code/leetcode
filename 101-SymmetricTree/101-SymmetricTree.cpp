// Last updated: 1/11/2026, 1:03:20 PM
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
    bool checkSymmetry(TreeNode* l, TreeNode* r){
        if(l==NULL||r==NULL){
            return l==r;
        }
        if(l->val!=r->val){
            return false;
        }
        return checkSymmetry(l->left,r->right)&&checkSymmetry(l->right,r->left);
    }
public:
    bool isSymmetric(TreeNode* root) {
        return root==NULL||checkSymmetry(root->left,root->right);
    }
};