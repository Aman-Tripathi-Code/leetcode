// Last updated: 10/7/2026, 4:53:56 AM
1class Solution {
2    public int minAddToMakeValid(String s) {
3        int len = s.length();
4        int brackets = 0, close = 0;
5        for(int i = 0; i<len; i++){
6            if(s.charAt(i) == '(') brackets++;
7            else{
8                if(brackets <= 0){
9                    close++;
10                }else{
11                    brackets--;
12                }
13            }
14        }
15        return brackets + close;
16    }
17}