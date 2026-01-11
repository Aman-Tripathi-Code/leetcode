// Last updated: 1/11/2026, 1:03:57 PM
class Solution {
private:
    void recursion(int ind, vector<int> &candidates, int target, vector<int>&ds,vector<vector<int>>&ans){
        //base case
        if(ind == candidates.size()){
            if(target==0){
                ans.push_back(ds);
            }
            return;
        }
        if(candidates[ind]<=target){
            ds.push_back(candidates[ind]);
            recursion(ind,candidates,target-candidates[ind],ds,ans);
            ds.pop_back();
        }
        //not take situation
        recursion(ind+1,candidates,target,ds,ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int>ds;
        recursion(0,candidates,target,ds,ans);
        return ans;
    }
};