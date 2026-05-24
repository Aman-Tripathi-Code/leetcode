// Last updated: 5/24/2026, 11:26:24 PM
1class Solution {
2public:
3    void rec(int ind, vector<int>&arr, int d, vector<int>& dp,int n){
4        if(dp[ind] != -1) return;
5        dp[ind] = 1;
6
7        for(int i = ind-1; i>=0 && ind-i <= d && arr[ind] > arr[i]; i--){
8            rec(i,arr,d,dp,n);
9            dp[ind] = max(dp[ind],dp[i]+1);
10        }
11
12        for(int i = ind+1; i<n && i-ind <= d && arr[ind] > arr[i]; i++){
13            rec(i,arr,d,dp,n);
14            dp[ind] = max(dp[ind],dp[i]+1);
15        }
16    }
17    int maxJumps(vector<int>& arr, int d) {
18        int n = arr.size();
19        vector<int> dp(n,-1);
20        for(int i = 0; i<n; i++){
21            rec(i,arr,d,dp,n);
22        }
23        return *max_element(dp.begin(),dp.end());        
24    }
25};