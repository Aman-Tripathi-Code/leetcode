// Last updated: 1/11/2026, 1:03:14 PM
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
    TreeNode* tree(vector<int>&inorder, int inStart, int inEnd, vector<int>&postorder, int postStart, int postEnd, map<int,int> &mp){
        if(inStart>inEnd||postStart>postEnd){
            return NULL;
        }
        int inorderInd = mp[postorder[postEnd]];
        TreeNode* root = new TreeNode(postorder[postEnd]);
        int leftNum = inorderInd- inStart;
        
        root->left = tree(inorder,inStart,inorderInd-1,postorder,postStart,postStart+leftNum-1,mp);
        root->right = tree(inorder,inorderInd+1,inEnd,postorder,postStart+leftNum,postEnd-1,mp);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int,int> mp;
        for(int i = 0; i<inorder.size(); i++){
            mp[inorder[i]] = i;
        }
        TreeNode* root =  tree(inorder,0,inorder.size()-1,postorder,0,postorder.size()-1,mp);
        return root;
    }
};