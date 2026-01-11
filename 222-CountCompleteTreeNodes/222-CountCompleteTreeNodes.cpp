// Last updated: 1/11/2026, 1:02:24 PM
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
    int leftheight(TreeNode *root){
        int height = 0;
        while(root){
            height++;
            root = root->left; 
        }
        return height;
    }
    int rightheight(TreeNode *root){
        int height = 0;
        while(root){
            height++;
            root = root->right;
        }
        return height;
    }
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int leftHeight = leftheight(root);
        int rightHeight = rightheight(root);
        cout << leftHeight << "  " << rightHeight << endl;
        if(leftHeight==rightHeight){
            return (1<<leftHeight)-1;
        }
        int leftCount = countNodes(root->left);
        int rightCount = countNodes(root->right);
        return 1+leftCount+rightCount;
    }
};