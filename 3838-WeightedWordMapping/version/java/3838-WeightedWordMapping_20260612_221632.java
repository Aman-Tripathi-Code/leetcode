// Last updated: 6/12/2026, 10:16:32 PM
1class Solution {
2    public String mapWordWeights(String[] words, int[] weights) {
3        StringBuilder ans = new StringBuilder(words.length);
4
5        for(String s : words){
6            int curr = 0;
7            for(int i = 0; i<s.length(); i++){
8                curr += weights[s.charAt(i) -'a'];
9            }
10            curr = curr % 26;
11            ans.append((char)('z'-curr));
12        }
13        return ans.toString();
14    }
15}