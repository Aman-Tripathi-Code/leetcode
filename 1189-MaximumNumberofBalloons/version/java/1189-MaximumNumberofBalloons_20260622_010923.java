// Last updated: 6/22/2026, 1:09:23 AM
1class Solution {
2    public int maxNumberOfBalloons(String text) {
3        int[] hs = new int[26];
4        int n = text.length();
5        for(int i = 0; i<n; i++){
6            hs[text.charAt(i)-'a']++;
7        }
8
9        return Math.min(hs['b'-'a'],Math.min(hs['a'-'a'],Math.min(hs['l'-'a']/2,Math.min(hs['o'-'a']/2,hs['n'-'a']))));
10    }
11}