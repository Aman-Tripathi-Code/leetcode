// Last updated: 4/26/2026, 2:42:19 AM
1
2class Solution {
3public:
4    long long map(int x, int y, int side){
5        if(y == 0){
6            return x; 
7        }
8        if(x == side){
9            return side + y;
10        }
11        if(y == side){
12            return 3LL * side - x;
13        }
14        return 4LL * side - y;
15    }
16    bool check(long long mid, vector<long long> &t, int n ,int k, int side){
17        vector<long long> extended(2*n);
18        for(int i = 0; i<n; i++){
19            extended[i] = t[i];
20            extended[i+n] = t[i] + 4LL*side;
21        }
22
23        for(int i = 0; i<n; i++){
24            long long count = 1;
25            long long curr = extended[i];
26            int index = i;
27            for(int cnt = 1; cnt<k; cnt++){
28                long long target = curr + mid;
29                auto it = lower_bound(extended.begin()+index+1, extended.begin()+i+n, target);
30                if(it == extended.begin()+i+n){
31                    count = -1;
32                    break;
33                }
34                index = it - extended.begin();
35                count++;
36                curr = extended[index];
37            }
38            if(count == k && (extended[i] + 4LL*side - curr) >= mid){
39                return true;
40            }
41        }
42        return false;
43    }
44    int maxDistance(int side, vector<vector<int>>& points, int k) {
45        int n = points.size();
46        vector<long long> t(n);
47        for(int i = 0; i<n; i++){
48            int x = points[i][0], y = points[i][1];
49            t[i] = map(x,y,side);
50        } 
51        sort(t.begin(),t.end());
52        long long ans = 0;
53        long long lo = 0, hi = 2*side;
54        while(lo <= hi){
55            long long mid = lo + (hi - lo)/2;
56            if(check(mid,t,n,k,side)){
57                ans = mid;
58                lo = mid + 1;
59            }else{
60                hi = mid - 1;
61            }
62        }
63        return ans;
64
65    }
66};