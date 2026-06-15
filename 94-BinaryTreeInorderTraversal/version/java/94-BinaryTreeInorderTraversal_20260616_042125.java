// Last updated: 6/16/2026, 4:21:25 AM
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
17    public List<Integer> inorderTraversal(TreeNode root) {
18        List<Integer> inorder = new ArrayList<>();
19        Deque<TreeNode> st = new ArrayDeque<>();
20        
21        while(true){
22            if(root != null){
23                st.push(root);
24                root = root.left;
25            }else{
26                if(st.isEmpty()){
27                    break;
28                }
29
30                root = st.poll();
31                inorder.add(root.val);
32                root = root.right;
33            }
34        }
35        return inorder;
36    }
37}