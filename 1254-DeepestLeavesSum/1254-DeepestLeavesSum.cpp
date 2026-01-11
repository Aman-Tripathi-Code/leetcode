// Last updated: 1/11/2026, 1:00:33 PM
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
    void inorder(TreeNode* root,priority_queue<pair<int,int>> &pq,int lvl){
        if(root==NULL){
            return;
        }
        pq.push({lvl,root->val});
        inorder(root->left,pq,lvl+1);
        inorder(root->right,pq,lvl+1);
    }
public:
    int deepestLeavesSum(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        priority_queue<pair<int,int>> pq;
        inorder(root,pq,0);
        int sum = 0;
        int height = pq.top().first;
        while(!pq.empty()){
            int newHeight = pq.top().first;
            int nodeVal = pq.top().second;
            pq.pop();
            if(newHeight!=height){
                break;
            }
            sum += nodeVal;
        }
        return sum;

    }
};