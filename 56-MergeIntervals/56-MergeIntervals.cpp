// Last updated: 1/11/2026, 1:03:45 PM
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        vector<int> tempInterval = intervals[0];
        int sz = intervals.size();
        for(auto it:intervals){
            if(tempInterval[1]>=it[0]){
                tempInterval[1] = max(tempInterval[1],it[1]);
            }
            else{
                ans.push_back(tempInterval);
                tempInterval = it;
            }
        }
        ans.push_back(tempInterval);
        return ans;
    }
};