// Last updated: 6/21/2026, 8:07:06 AM
1class Solution {
2public:
3    int maxDistance(string moves) {
4        int lcount = count(moves.begin(),moves.end(),'L');
5        int rcount = count(moves.begin(),moves.end(),'R');
6        int ucount = count(moves.begin(),moves.end(),'U');
7        int dcount = count(moves.begin(),moves.end(),'D');
8        int _count = count(moves.begin(),moves.end(),'_');
9
10        if(lcount > rcount){
11            lcount += _count;
12        }else rcount += _count;
13
14        return abs(lcount - rcount) + abs(ucount - dcount);
15    }
16};