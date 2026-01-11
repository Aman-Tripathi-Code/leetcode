// Last updated: 1/11/2026, 1:03:56 PM
class Solution {
private:
    void solve(int ind, vector<int>& ds, vector<int> &candidates, int target, vector<vector<int>>& ans){
        if(target==0){
            ans.push_back(ds);
        }
        for(int i = ind; i<candidates.size(); i++){
            if(i>ind && candidates[i]==candidates[i-1]){
                continue;
            }
            if(candidates[ind]>target){
                break;
            }
            ds.push_back(candidates[i]);
            solve(i+1,ds,candidates,target-candidates[i],ans);
            ds.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> ds;
        vector<vector<int>> ans;
        sort(candidates.begin(), candidates.end());
        solve(0,ds,candidates,target,ans);
        return ans;
    }
};