// Last updated: 6/20/2026, 3:03:29 PM
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
17    public List<Integer> postorderTraversal(TreeNode root) {
18        
19        List<Integer> postOrder = new ArrayList<>();
20
21        if(root == null){
22            return postOrder;
23        }
24
25        Deque<TreeNode> st1 = new ArrayDeque<>();
26        Deque<TreeNode> st2 = new ArrayDeque<>();
27
28        st1.push(root);
29
30        while(!st1.isEmpty()){
31            TreeNode node = st1.pop();
32
33            st2.push(node);
34            if(node.left != null){
35                st1.push(node.left);
36            }
37            if(node.right != null){
38                st1.push(node.right);
39            }
40        }
41
42        while(!st2.isEmpty()){
43            TreeNode node = st2.pop();
44            postOrder.add(node.val);
45        }
46
47        return postOrder;
48    }
49}