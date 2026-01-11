// Last updated: 1/11/2026, 1:02:14 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
//LCA - Lowest Common Ancestor of two nodes is lowest node in tree which has both the node as its desecendant(where a node can 
//be it own desecendant).
//Naive-is to store the path of node from root for both the nodes and check the last common node.
//Optimal-we can perform a recursive dfs in which we call the left and right side of a node
//we will start from root and call the dfs
//Base condition - if we have root as null or root as either of the node we just return the root
//after the both side of a node is explore we check if either of left or right call is null we just return opposite of it and if
//we have neither of them null we just return the node and this we will be our ans
//because in dfs call either we are returning the root as the node for which th lca is to be find or null and if we get our both
//left and right side as the nodes we can say that it is the lowest node that is ancestor of both of the nodes.
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root==NULL||root==p||root==q){
            return root;
        }
        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);
        if(left==NULL){
            return right;
        }
        else if(right == NULL){
            return left;
        }
        else return root;
    }
};