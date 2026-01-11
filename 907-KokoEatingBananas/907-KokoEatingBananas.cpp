// Last updated: 1/11/2026, 1:01:01 PM
class Solution {
public:
    bool check(int x, vector<int>& piles, int n, int h){
        long long cnt = 0;
        for(auto pile: piles){
            cnt += (pile + x - 1)/x;
        }
        return cnt <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int lo = 1, hi = *max_element(piles.begin(),piles.end()), ans = 0;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(check(mid,piles,n,h)){
                hi = mid - 1;
                ans = mid;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};