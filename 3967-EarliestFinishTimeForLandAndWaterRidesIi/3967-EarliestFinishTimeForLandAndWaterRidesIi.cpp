// Last updated: 6/8/2026, 2:07:34 AM
class Solution {
public:
    int findMinDurationAfter(int x, vector<int>& start, vector<int>& duration){
        int n = start.size();
        int mini = 1e9;
        for(int i = 0; i<n; i++){
            if(start[i] <= x){
                mini = min(mini,duration[i]);
            }else{
                mini = min(mini,(start[i]-x+duration[i]));
            }
        }
        return mini;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        int n = landStartTime.size(), m = waterStartTime.size();
        int landEndTime = INT_MAX, waterEndTime = INT_MAX;
        for(int i = 0; i<n; i++){
            landEndTime = min(landEndTime, landStartTime[i]+landDuration[i]);
        }
        for(int i = 0; i<m; i++){
            waterEndTime = min(waterStartTime[i] + waterDuration[i], waterEndTime);
        }

        return min(landEndTime+ findMinDurationAfter(landEndTime,waterStartTime,waterDuration),
        waterEndTime + findMinDurationAfter(waterEndTime,landStartTime,landDuration));
    }
};