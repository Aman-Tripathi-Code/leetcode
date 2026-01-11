// Last updated: 1/11/2026, 1:02:49 PM
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
        void postorderTrav(TreeNode* root, vector<int>& postorder){
            if(root==NULL){
                return;
            }
            postorderTrav(root->left , postorder);
            postorderTrav(root->right, postorder);
            postorder.push_back(root->val);
        }
        //using 2 stack
        void postorderTrav2stacks(TreeNode* root, vector<int>&preorder){
            if(root==NULL){
                return;
            }
            stack<TreeNode*> st1,st2;
            st1.push(root);
            while(!st1.empty()){
                root = st1.top();
                st1.pop();
                st2.push(root);
                if(root->left!=NULL){
                    st1.push(root->left);
                }
                if(root->right!=NULL){
                    st1.push(root->right);
                }
            }
            while(!st2.empty()){
                preorder.push_back(st2.top()->val);
                st2.pop();
            }
        }
        //using 1 stack
        void postorderTrav1stack(TreeNode* root, vector<int>& postorder){
            stack<TreeNode*> st;
            while(root!=NULL || !st.empty()){
                if(root!=NULL){
                    st.push(root);
                    root = root -> left;
                }
                else{
                    TreeNode* temp = st.top()->right;
                    if(temp==NULL){
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                        while(!st.empty()&&temp == st.top()->right){
                            temp = st.top();
                            st.pop();
                            postorder.push_back(temp->val);
                        }
                    }
                    else root = temp;
                }
            }
        }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int>ans;
        postorderTrav1stack(root,ans);
        return ans;
    }
};