// Last updated: 7/6/2026, 2:10:26 AM
1class Solution {
2public:
3    static bool cmp(vector<int>&a , vector<int>&b){
4        if(a[0] == b[0]){
5            return a[1] > b[1]; 
6        }
7        return a[0] < b[0];
8    }
9    int removeCoveredIntervals(vector<vector<int>>& intervals) {
10        int n = intervals.size();
11        sort(intervals.begin(),intervals.end(),cmp);
12        int start = intervals[0][0], end = intervals[0][1];
13        int cnt = 0;
14        for(int i = 1; i<n; i++){
15            if(intervals[i][0] > end){
16                start = intervals[i][0];
17                end = intervals[i][1];
18            }else if(intervals[i][1] > end){
19                end = intervals[i][1];
20            }else{
21                cnt++;
22            }
23        }
24        return n-cnt;
25    }
26};