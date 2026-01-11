// Last updated: 1/11/2026, 1:02:36 PM
class Solution {
public:
    int hammingWeight(uint32_t n) {
        int cnt = 0;
        while(n>0){
            n = n&(n-1);
            cnt++;
        }
        return cnt;
    }
};