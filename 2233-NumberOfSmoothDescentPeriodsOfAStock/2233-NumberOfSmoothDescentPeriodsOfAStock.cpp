// Last updated: 1/11/2026, 12:59:48 PM
class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long ans = n, curr = 1;
        for(int i = 1; i<n; i++){
            if(prices[i] == prices[i-1] - 1){
                curr++;
            }
            else{
                ans -= curr;
                ans += (curr*(curr+1))/2;
                curr = 1;
            }
        }
        if(curr > 1){
           ans -= curr;
            ans += (curr*(curr+1))/2; 
        }
        return ans;
    }
};