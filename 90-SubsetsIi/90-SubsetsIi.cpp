// Last updated: 1/11/2026, 1:03:25 PM
class Solution {
    private: void solve(int ind, vector<int> &nums, vector<vector<int>> &ans,vector<int> &ds){
        
        ans.push_back(ds);
        for(int i = ind; i<nums.size(); i++){
            if(ind!=i && nums[i]==nums[i-1]){
                continue;
            }
            ds.push_back(nums[i]);
            solve(i+1,nums,ans,ds);
            ds.pop_back();
        }
    }
    
    public:
        vector<vector<int>> subsetsWithDup(vector<int>& nums) {
            sort(nums.begin(), nums.end());
            vector<vector<int>> ans;
            vector<int> ds;
            int ind = 0;
            solve(ind,nums,ans,ds);
            return ans;
        }
};