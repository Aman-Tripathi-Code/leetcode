// Last updated: 1/11/2026, 1:00:19 PM
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
    void preorder(TreeNode* root, int &count , int maxi){
        if(!root) return;
        if(maxi<=root->val){
            count++;
        }
        maxi = max(maxi,root->val);
        preorder(root->left,count,maxi);
        preorder(root->right,count,maxi);
    }
public:
    int goodNodes(TreeNode* root) {
        int count = 0;
        int maxi = root->val;
        preorder(root,count,maxi);
        return count;
    }
};