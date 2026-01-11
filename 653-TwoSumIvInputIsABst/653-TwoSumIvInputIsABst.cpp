// Last updated: 1/11/2026, 1:01:24 PM
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

class BSTIterator{
stack<TreeNode*> st;
bool reverse = false;
public:
    BSTIterator(TreeNode* root, bool isReversed){
        reverse = isReversed;
        pushAll(root);
    }
    int next(){
        TreeNode* temp = st.top();
        st.pop();
        (reverse) ? pushAll(temp->left) : pushAll(temp->right);
        return temp->val;
    }

    void pushAll(TreeNode* root){
        if(reverse){
            while(root){
                st.push(root);
                root = root->right;
            }
        }
        else{
            while(root){
                st.push(root);
                root = root->left;
            }
        }
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        BSTIterator l(root,false);
        BSTIterator r(root,true);

        int i = l.next();
        int j = r.next();

        while(i<j){
            if(i + j == k){
                return true;
            }
            else if(i + j < k){
                i = l.next();
            }
            else j = r.next();
        }
        return false;
    }
};