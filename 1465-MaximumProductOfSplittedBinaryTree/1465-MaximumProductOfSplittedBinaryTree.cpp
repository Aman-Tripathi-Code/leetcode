// Last updated: 1/11/2026, 1:00:22 PM
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int mod = 1e9 + 7;
    void inorderSum(TreeNode* root, long long &sum){
        if(root == nullptr){
            return;
        }
        inorderSum(root->left,sum);
        sum += root->val;
        inorderSum(root->right,sum);
    }
    long long  rec(TreeNode* root, long long totalSum, long long & maxi) {
        if (root == nullptr) {
            return 0;
        }
        long long  leftSum = 0, rightSum = 0;
        if (root->left)
            leftSum =rec(root->left, totalSum, maxi);
        if (root->right)
            rightSum =rec(root->right, totalSum, maxi);
        long long parSum = totalSum - (root->val + leftSum + rightSum);
        maxi = max(maxi,max(((parSum + root->val + leftSum) * rightSum),
                   ((parSum + root->val + rightSum) * leftSum)));
        return leftSum + rightSum + root->val;
    }
    int maxProduct(TreeNode* root) {
        long long ans = 0,totalSum = 0;
        inorderSum(root, totalSum);
        rec(root, totalSum, ans);
        return ans % mod;
    }
};