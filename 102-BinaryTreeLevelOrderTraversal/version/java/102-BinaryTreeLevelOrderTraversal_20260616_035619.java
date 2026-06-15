// Last updated: 6/16/2026, 3:56:19 AM
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
17    public List<List<Integer>> levelOrder(TreeNode root) {
18        if (root == null)
19            return new ArrayList<>();
20        ;
21        List<List<Integer>> levelArray = new ArrayList<>();
22        Queue<TreeNode> q = new ArrayDeque<TreeNode>();
23        q.offer(root);
24        int lvl = 0;
25        while (!q.isEmpty()) {
26            levelArray.add(new ArrayList<>());
27            int sz = q.size();
28            for (int i = 0; i < sz; i++) {
29                TreeNode node = q.poll();
30                levelArray.get(lvl).add(node.val);
31                if (node.left != null) {
32                    q.offer(node.left);
33                }
34                if (node.right != null) {
35                    q.offer(node.right);
36                }
37            }
38            lvl++;
39        }
40        return levelArray;
41    }
42}