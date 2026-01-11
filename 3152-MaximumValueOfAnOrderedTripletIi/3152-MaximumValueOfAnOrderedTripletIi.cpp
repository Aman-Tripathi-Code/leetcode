// Last updated: 1/11/2026, 12:59:26 PM
class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        long long ans = 0;
        vector<int> fwd(n), bwd(n);
        fwd[0] = nums[0];
        bwd[n-1] = nums[n-1];
        for(int i = 1; i<n; i++){
            fwd[i] = max(fwd[i-1],nums[i]);
        }
        for(int i = n-2; i>=0; i--){
            bwd[i] = max(bwd[i+1],nums[i]);
        }

        for(int i = 1; i<n-1; i++){
            long long temp = (fwd[i-1]-nums[i]) *1LL * bwd[i+1];
            if(temp > ans) ans = temp;
        }
        return ans;
    }
};