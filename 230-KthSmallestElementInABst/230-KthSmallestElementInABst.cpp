// Last updated: 1/11/2026, 1:02:19 PM
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
    int kthSmallest(TreeNode* root, int k) {
        int cnt = 0, ans = -1;
        while(root){
            if(root->left==NULL){
                cnt++;
                if(cnt == k){
                    ans = root->val;
                }
                root = root->right;
            }
            else{
                TreeNode* temp = root->left;
                while(temp->right && temp->right!=root){
                    temp = temp->right;
                }
                if(temp->right==NULL){
                    temp->right = root;
                    root = root->left;
                }
                else{
                    temp->right = NULL;
                    cnt++;
                    if(cnt == k){
                        ans = root->val;
                    }
                    root = root->right;
                }
            }
        }
        return ans;
    }
};