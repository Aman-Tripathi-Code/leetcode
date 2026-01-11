// Last updated: 1/11/2026, 1:02:12 PM
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n+2,1);
        vector<int> suf(n+2,1);

        for(int i = 0; i<n; i++){
            pre[i+1] = nums[i] * pre[i];
        }
        for(int i = n-1; i>=0; i--){
            suf[i+1] = nums[i] * suf[i+2];
        }
        vector<int> ans(n);
        for(int i = 1; i<=n; i++){
            ans[i-1] = pre[i-1] * suf[i+1];
        }
        return ans;
    }
};