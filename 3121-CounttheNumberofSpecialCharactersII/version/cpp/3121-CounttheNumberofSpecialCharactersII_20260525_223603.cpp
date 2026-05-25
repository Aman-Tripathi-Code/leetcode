// Last updated: 5/25/2026, 10:36:03 PM
1class Solution {
2public:
3    int numberOfSpecialChars(string word) {
4        int small = 0, cap = 0;
5        for(char &ch: word){
6            int shift = 0;
7            if(ch >= 'a' && ch <= 'z'){
8                shift = 1 << (ch - 'a');
9                small = (cap & shift) ? ((small & shift) ? (small ^ shift) : small) : (small | shift);
10            }
11            if(ch >= 'A' && ch <= 'Z'){
12                shift = 1 << (ch - 'A');
13                cap |= shift;
14            }
15        }
16        return __builtin_popcount(small&cap);
17    }
18};