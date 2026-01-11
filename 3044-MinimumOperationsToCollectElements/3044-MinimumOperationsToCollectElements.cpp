// Last updated: 1/11/2026, 12:59:27 PM
class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int n = nums.size();
        set<int> st;
        for(int i = n-1; i>=0 ; i--){
            if(nums[i] <= k){
                st.insert(nums[i]);
            }
            if(st.size() == k){
                return n-i;
            }
        }
        return -1;
    }
};