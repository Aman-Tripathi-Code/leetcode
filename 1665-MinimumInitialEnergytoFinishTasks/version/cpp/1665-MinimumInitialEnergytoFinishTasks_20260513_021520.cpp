// Last updated: 5/13/2026, 2:15:20 AM
1class Solution {
2public:
3    static bool cmp(vector<int>&a, vector<int>&b){
4        return (a[1] - a[0]) > (b[1] - b[0]);
5    }
6    int minimumEffort(vector<vector<int>>& tasks) {
7        int n = tasks.size();
8        sort(tasks.begin(),tasks.end(),cmp);
9        long long maxi = 0, sum = 0;
10        for(int i = 0; i<n; i++){
11            maxi = max(maxi,sum + tasks[i][1]);
12            sum += tasks[i][0];
13        }
14        return maxi;
15    }
16};