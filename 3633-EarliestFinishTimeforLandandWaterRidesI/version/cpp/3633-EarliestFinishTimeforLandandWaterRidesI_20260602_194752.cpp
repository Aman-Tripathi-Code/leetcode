// Last updated: 6/2/2026, 7:47:52 PM
1class Solution {
2public:
3    int findMinDurationAfter(int x, vector<int>& start, vector<int>& duration){
4        int n = start.size();
5        int mini = 1e9;
6        for(int i = 0; i<n; i++){
7            if(start[i] <= x){
8                mini = min(mini,duration[i]);
9            }else{
10                mini = min(mini,(start[i]-x+duration[i]));
11            }
12        }
13        return mini;
14    }
15    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
16        int n = landStartTime.size(), m = waterStartTime.size();
17        int landEndTime = INT_MAX, waterEndTime = INT_MAX;
18        for(int i = 0; i<n; i++){
19            landEndTime = min(landEndTime, landStartTime[i]+landDuration[i]);
20        }
21        for(int i = 0; i<m; i++){
22            waterEndTime = min(waterStartTime[i] + waterDuration[i], waterEndTime);
23        }
24
25        return min(landEndTime+ findMinDurationAfter(landEndTime,waterStartTime,waterDuration),
26        waterEndTime + findMinDurationAfter(waterEndTime,landStartTime,landDuration));
27    }
28};