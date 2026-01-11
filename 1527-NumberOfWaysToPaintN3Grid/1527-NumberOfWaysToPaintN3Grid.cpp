// Last updated: 1/11/2026, 1:00:20 PM
class Solution {
public:
    int numOfWays(int n) {
        int mod = 1e9+ 7;
        long long x = 6, y = 6;
        for(int i = 1; i<n; i++){
            long long nx = 3*x + 2*y;
            long long ny = 2*x + 2*y;
            x = nx % mod;
            y = ny % mod;
        } 
        return (x + y) % mod;
    }
};