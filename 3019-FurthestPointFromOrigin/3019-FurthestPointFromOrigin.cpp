// Last updated: 6/8/2026, 2:07:58 AM
class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int lCount = 0, rCount = 0, _Count = 0;
        for(char move: moves){
            (move == 'R') ? rCount++ : (move == 'L') ? lCount++ : _Count++;
        }
        return _Count + abs(rCount - lCount);
    }
};