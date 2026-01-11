// Last updated: 1/11/2026, 12:59:37 PM
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto it:nums){
            vector<int> ds;
            while(it){
                int rem = it%10;
                ds.push_back(rem);
                it /= 10;
            }
            reverse(ds.begin(),ds.end());
            for(auto it1:ds){
                ans.push_back(it1);
            }
        }
        return ans;
    }
};