// Last updated: 10/8/2026, 11:06:05 PM
1class Solution {
2    public String removeOuterParentheses(String s) {
3        int n = s.length(), balance = 0;
4        StringBuilder ans = new StringBuilder(n);
5        for(char ch : s.toCharArray()){
6            if(ch == '('){
7                if(balance > 0) ans.append(ch);
8                balance++;
9            }
10            else{
11                if(balance > 1) ans.append(ch);
12                balance--;
13            }
14        }
15        return ans.toString();
16    }
17}