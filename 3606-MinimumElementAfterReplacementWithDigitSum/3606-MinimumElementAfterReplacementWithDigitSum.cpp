// Last updated: 6/8/2026, 2:07:43 AM
class Solution {
public:
    int sumOfDigits(int n){
        int sum = 0;
        while(n){
            sum += n % 10;
            n /= 10;
        }
        return sum;
    }
    int minElement(vector<int>& nums) {
        int mini = 40;
        for(auto &x: nums){
            int sum = sumOfDigits(x);
            mini = min(sum,mini);
        }
        return mini;
    }
};