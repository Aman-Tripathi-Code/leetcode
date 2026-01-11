// Last updated: 1/11/2026, 1:02:50 PM
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
    //recursive
    void preorderTrav(TreeNode* curr, vector<int> & preorder){
        if(curr==NULL){
            return;
        }
        preorder.push_back(curr->val);
        preorderTrav(curr->left,preorder);
        preorderTrav(curr->right,preorder);
    }
    //iterative
    void preOrderTrav(TreeNode* root, vector<int> &preorder){
        TreeNode* curr = root;
        while(curr){
            if(curr->left==NULL){
                preorder.push_back(curr->val);
                curr= curr->right;
            }
            else{
                TreeNode* prev = curr->left;
                while(prev->right&&prev->right!=curr){
                    prev = prev->right;
                }
                if(prev->right==NULL){
                    prev->right = curr;
                    preorder.push_back(curr->val);
                    curr = curr->left;
                }
                else{
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        // preorderTrav(root,ans);
        preOrderTrav(root,ans);
        return ans;
    }
};