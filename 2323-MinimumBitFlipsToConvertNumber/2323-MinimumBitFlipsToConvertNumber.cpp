// Last updated: 1/11/2026, 12:59:45 PM
class Solution {
public:
    int minBitFlips(int start, int goal) {
        int cnt = 0;
        for(int i = 0; i<32; i++){
            int startBit = start & (1<<i);
            int goalBit = goal & (1<<i);
            if(startBit^goalBit){
                cnt++;
            }
        }
        return cnt;
    }
};