// Last updated: 1/11/2026, 1:03:31 PM
class Solution {
    private:
        void generateSubsets(int ind , vector<int>&ds, vector<int>& nums, vector<vector<int>>& ans){
            if(ind==nums.size()){
                ans.push_back(ds);
                return;
            }
            //picking the index
            ds.push_back(nums[ind]);
            generateSubsets(ind+1,ds,nums,ans);
            
            //not picking the index
            ds.pop_back();
            generateSubsets(ind+1,ds,nums,ans);
        }
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<int> ds;
            vector<vector<int>> ans;
            generateSubsets(0,ds,nums,ans);
            return ans;
        }
};