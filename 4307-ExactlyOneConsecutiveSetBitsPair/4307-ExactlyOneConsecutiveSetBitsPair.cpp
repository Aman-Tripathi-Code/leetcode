// Last updated: 6/8/2026, 2:07:23 AM
class Solution {
public:
    bool consecutiveSetBits(int n) {
        int maxi = 0,cnt = 0, counter = 0;
        while(n){
            if(n & 1){
                cnt++;
                if(cnt == 2) counter++;
                maxi = max(maxi,cnt);
            }else{
                cnt = 0;
            }
            n >>= 1;
        }
        return (maxi == 2 && counter == 1);
    }
};