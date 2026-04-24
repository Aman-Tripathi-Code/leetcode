// Last updated: 4/24/2026, 8:36:31 AM
1class Solution {
2public:
3    int furthestDistanceFromOrigin(string moves) {
4        int lCount = count(moves.begin(),moves.end(),'L'), rCount = count(moves.begin(),moves.end(),'R'), 
5        remCount = count(moves.begin(),moves.end(),'_');
6        return remCount + abs(lCount - rCount);
7    }
8};