// Last updated: 5/25/2026, 10:27:15 PM
1class Solution {
2public:
3    int numberOfSpecialChars(string word) {
4        int small = 0, cap = 0;
5        for(char &ch: word){
6            int shift = 0;
7            if(ch >= 'a' && ch <= 'z'){
8                shift = 1 << (ch - 'a');
9                if(shift & cap){
10                    if(small & shift){
11                        small ^= shift;
12                    }
13                }
14                else small |= shift;
15            }
16            if(ch >= 'A' && ch <= 'Z'){
17                shift = 1 << (ch - 'A');
18                cap |= shift;
19            }
20        }
21        cout << small << ' ' << cap << endl;
22        return __builtin_popcount(small&cap);
23    }
24};