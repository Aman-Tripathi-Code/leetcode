// Last updated: 10/7/2026, 5:03:19 AM
1class Solution {
2    public int minAddToMakeValid(String s) {
3        int len = s.length();
4        int open = 0, close = 0;
5        for(int i = 0; i<len; i++){
6            if(s.charAt(i) == '(') open++;
7            else{
8                if(open <= 0){
9                    close++;
10                }else{
11                    open--;
12                }
13            }
14        }
15        return open + close;
16    }
17}