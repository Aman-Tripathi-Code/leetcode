// Last updated: 1/11/2026, 1:04:15 PM
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0) return false;
        long long res = 0;
        int n = x;
        while(x){
            res = res*10 + (x%10);
            x /= 10;
        }
        cout << res;
        return (res == n);
    }
};