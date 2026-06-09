// Last updated: 6/9/2026, 11:16:31 PM
1class Solution {
2    boolean isVowel(char ch){
3        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u');
4    }
5    public int beautifulSubstrings(String s, int k) {
6        int n = s.length(), cnt = 0;
7        for(int i = 0; i<n; i++){
8            int vowel = 0, cons = 0;
9            for(int j = i; j<n; j++){
10                if(isVowel(s.charAt(j))) vowel++;
11                else cons++;
12                if((vowel == cons) && ((vowel * cons)%k == 0)) cnt++;
13            }
14        }
15        return cnt;
16    }
17}