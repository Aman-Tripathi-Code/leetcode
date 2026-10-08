// Last updated: 10/8/2026, 11:01:19 PM
1class Solution {
2    public String removeOuterParentheses(String s) {
3        int n = s.length(), balance = 0;
4        StringBuffer ans = new StringBuffer();
5        for(int i = 0; i<n; i++){
6            char ch = s.charAt(i);
7            if(ch == '('){
8                if(balance > 0) ans.append(ch);
9                balance++;
10            }
11            else{
12                if(balance > 1) ans.append(ch);
13                balance--;
14            }
15        }
16        return ans.toString();
17    }
18}