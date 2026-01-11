// Last updated: 1/11/2026, 1:01:27 PM
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
    bool sameTree(TreeNode* p, TreeNode* q){
        if(p==NULL || q==NULL){
            return p==q;
        }
        return p->val==q->val && sameTree(p->left,q->left) && sameTree(p->right,q->right);
    }
public:
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        stack<TreeNode*> st;
        TreeNode* curr = root;
        st.push(curr);
        while(!st.empty()){
            TreeNode* node = st.top();
            st.pop();
            if(node->val==subRoot->val){
                if(sameTree(node,subRoot)){
                    return true;
                }
            }
            if(node->right){
                st.push(node->right);
            }
            if(node->left){
                st.push(node->left);
            }
        }
        return false;
    }
};