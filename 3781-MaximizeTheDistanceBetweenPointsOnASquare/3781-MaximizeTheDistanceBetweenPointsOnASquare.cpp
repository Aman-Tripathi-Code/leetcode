// Last updated: 6/8/2026, 2:07:40 AM

class Solution {
public:
    long long map(int x, int y, int side){
        if(y == 0){
            return x; 
        }
        if(x == side){
            return side + y;
        }
        if(y == side){
            return 3LL * side - x;
        }
        return 4LL * side - y;
    }
    bool check(long long mid, vector<long long> &t, int n ,int k, int side){
        vector<long long> extended(2*n);
        for(int i = 0; i<n; i++){
            extended[i] = t[i];
            extended[i+n] = t[i] + 4LL*side;
        }

        for(int i = 0; i<n; i++){
            long long count = 1;
            long long curr = extended[i];
            int index = i;
            for(int cnt = 1; cnt<k; cnt++){
                long long target = curr + mid;
                auto it = lower_bound(extended.begin()+index+1, extended.begin()+i+n, target);
                if(it == extended.begin()+i+n){
                    count = -1;
                    break;
                }
                index = it - extended.begin();
                count++;
                curr = extended[index];
            }
            if(count == k && (extended[i] + 4LL*side - curr) >= mid){
                return true;
            }
        }
        return false;
    }
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int n = points.size();
        vector<long long> t(n);
        for(int i = 0; i<n; i++){
            int x = points[i][0], y = points[i][1];
            t[i] = map(x,y,side);
        } 
        sort(t.begin(),t.end());
        long long ans = 0;
        long long lo = 0, hi = 2*side;
        while(lo <= hi){
            long long mid = lo + (hi - lo)/2;
            if(check(mid,t,n,k,side)){
                ans = mid;
                lo = mid + 1;
            }else{
                hi = mid - 1;
            }
        }
        return ans;

    }
};