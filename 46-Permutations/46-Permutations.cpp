// Last updated: 1/11/2026, 1:03:51 PM
class Solution {
private:
    void solver(vector<int> &vis, vector<int> &ds, vector<vector<int>> &ans, vector<int> &nums, int n){
        if(ds.size()==n){
            ans.push_back(ds);
            return;
        }
        for(int i = 0; i<n ; i++){
            if(!vis[i]){
                ds.push_back(nums[i]);
                vis[i] = 1;
                solver(vis,ds,ans,nums,n);
                ds.pop_back();
                vis[i] = 0;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> ds;
        vector<vector<int>> ans;
        int n = nums.size();
        vector<int> vis(n,0);
        solver(vis,ds,ans,nums,n);
        return ans;
    }
};