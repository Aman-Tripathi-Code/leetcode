// Last updated: 7/23/2026, 2:07:41 AM
1class Solution {
2public:
3    bool check(int mid, vector<int>&piles, int n, int h){
4        long long hours = 0;
5        for(int i = 0; i<n; i++){
6            hours += (piles[i] + mid - 1)/mid;
7        }
8        return hours <= h;
9    }
10    int minEatingSpeed(vector<int>& piles, int h) {
11        int n = piles.size();
12        int lo = 1, hi = *max_element(piles.begin(),piles.end());
13        int ans = 0;
14        while(lo <= hi){
15            int mid = lo + (hi - lo)/2;
16
17            if(check(mid,piles,n,h)){
18                ans = mid;
19                hi = mid - 1;
20            }else{
21                lo = mid + 1;
22            }
23        }
24        return ans;
25
26
27
28    }
29};