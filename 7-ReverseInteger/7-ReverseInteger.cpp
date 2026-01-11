// Last updated: 1/11/2026, 1:04:17 PM
class Solution {
public:
    int reverse(int x) {
        long long res = 0;
        while(x){
            int rem = x%10;
            res = res*10 + rem;
            x /= 10; 
        }
        cout << res;
        if(res>=INT_MAX || res<=INT_MIN){
            return 0;
        }
        return res;
    }
};