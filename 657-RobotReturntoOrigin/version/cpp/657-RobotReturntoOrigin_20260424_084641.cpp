// Last updated: 4/24/2026, 8:46:41 AM
1class Solution {
2public:
3    bool judgeCircle(string moves) {
4        int x = 0, y = 0;
5        for(char move : moves){
6            (move == 'U') ? y++ : (move == 'D') ? y-- : (move == 'L') ? x-- : x++;
7        }
8        return (x == 0) & (y == 0);
9    }
10};