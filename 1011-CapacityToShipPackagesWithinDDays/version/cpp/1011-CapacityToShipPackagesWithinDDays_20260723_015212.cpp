// Last updated: 7/23/2026, 1:52:12 AM
1class Solution {
2public:
3    bool check(int mid, vector<int>&weights, int days){
4        int n = weights.size();
5        int cntDays = 1, currWeight = 0;
6        for(int i = 0; i<n; i++){
7            currWeight += weights[i];
8            if(currWeight > mid){
9                currWeight = weights[i];
10                cntDays++;
11            }
12        }
13        return cntDays <= days;
14    }
15    int shipWithinDays(vector<int>& weights, int days) {
16        int n = weights.size();
17        int sumOfWeight = accumulate(weights.begin(),weights.end(),0);
18
19        int lo = *max_element(weights.begin(),weights.end()), hi = sumOfWeight;
20        int ans = 0;
21        while(lo <= hi){
22            int mid = lo + (hi - lo)/2;
23
24            if(check(mid,weights,days)){
25                ans = mid;
26                hi = mid - 1;
27            }else{
28                lo = mid + 1;
29            }
30        }
31        return ans;
32    }
33};