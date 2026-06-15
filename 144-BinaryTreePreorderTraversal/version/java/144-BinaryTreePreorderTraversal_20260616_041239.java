// Last updated: 6/16/2026, 4:12:39 AM
1/**
2 * Definition for a binary tree node.
3 * public class TreeNode {
4 *     int val;
5 *     TreeNode left;
6 *     TreeNode right;
7 *     TreeNode() {}
8 *     TreeNode(int val) { this.val = val; }
9 *     TreeNode(int val, TreeNode left, TreeNode right) {
10 *         this.val = val;
11 *         this.left = left;
12 *         this.right = right;
13 *     }
14 * }
15 */
16class Solution {
17    public List<Integer> preorderTraversal(TreeNode root) {
18        if(root == null) return new ArrayList<>();
19        List<Integer> preorder = new ArrayList<Integer>();
20        Deque<TreeNode> st = new ArrayDeque<TreeNode>();
21
22        st.push(root);
23
24        while(!st.isEmpty()){
25            TreeNode node = st.peek();
26            st.pop();
27
28            preorder.add(node.val);
29
30            if(node.right != null) st.push(node.right);
31            if(node.left != null) st.push(node.left);
32            
33        }
34
35        return preorder;
36    }
37}