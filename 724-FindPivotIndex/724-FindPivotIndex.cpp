// Last updated: 1/11/2026, 1:01:17 PM
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> suf(n);
        pre[0] = nums[0];
        suf[0] = nums[n-1];
        for(int i = 1; i<n ; i++){
            pre[i] = pre[i-1] + nums[i];
            suf[i] = suf[i-1] + nums[n-1-i];
        }
        for(int i = 0; i<n; i++){
            if(pre[i]==suf[n-i-1]){
                return i;
            }
        }
        return -1;
    }
};