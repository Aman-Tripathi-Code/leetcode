// Last updated: 5/20/2026, 2:16:10 PM
1class Solution {
2public:
3    bool isVowel(char &ch){
4        return (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U');
5    }
6    bool halvesAreAlike(string s) {
7        int rightCnt = 0, leftCnt = 0, n = s.length();
8
9        for(int i = 0; i<n/2; i++){
10            if(isVowel(s[i])) leftCnt++;
11            if(isVowel(s[n-1-i])) rightCnt++;
12        }
13        return leftCnt == rightCnt;
14    }
15};