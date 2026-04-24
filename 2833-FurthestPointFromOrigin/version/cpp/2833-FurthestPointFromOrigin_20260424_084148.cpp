// Last updated: 4/24/2026, 8:41:48 AM
1class Solution {
2public:
3    int furthestDistanceFromOrigin(string moves) {
4        int lCount = 0, rCount = 0, _Count = 0;
5        for(char move: moves){
6            (move == 'R') ? rCount++ : (move == 'L') ? lCount++ : _Count++;
7        }
8        return _Count + abs(rCount - lCount);
9    }
10};