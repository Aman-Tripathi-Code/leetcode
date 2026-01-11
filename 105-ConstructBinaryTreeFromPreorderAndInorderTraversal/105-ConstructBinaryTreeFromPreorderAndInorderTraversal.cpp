// Last updated: 1/11/2026, 1:03:15 PM
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
    TreeNode* tree(vector<int>& preorder,int preStart,int preEnd, vector<int>& inorder, int inStart,int inEnd,unordered_map<int,int> &mp){
        if(preStart>preEnd||inStart>inEnd) return NULL;
        int inorderIndex = mp[preorder[preStart]];
        int nodeVal = inorder[inorderIndex];
        int numsLeft = inorderIndex-inStart;
        TreeNode* root = new TreeNode(nodeVal);
        root->left = tree(preorder,preStart+1,preStart+numsLeft,inorder,inStart,inorderIndex-1,mp);
        root->right = tree(preorder,preStart+numsLeft+1,preEnd,inorder,inorderIndex+1,inEnd,mp);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> inorderMap;
        for(int i = 0; i<inorder.size(); i++){
            inorderMap[inorder[i]] = i;
        }
        TreeNode *root = tree(preorder,0,preorder.size()-1,inorder,0,inorder.size()-1,inorderMap);
        return root;
    }
};