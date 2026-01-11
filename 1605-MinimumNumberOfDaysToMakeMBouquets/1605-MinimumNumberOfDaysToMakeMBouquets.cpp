// Last updated: 1/11/2026, 1:00:14 PM
class Solution {
public:
    bool check(int x, vector<int>& bloomDay, int m, int k){
        int cnt = 0;
        for(auto day: bloomDay){
            if(day <= x){
                cnt++;
                if(cnt == k){
                    m--;
                    cnt = 0;
                }
            }
            else cnt = 0;
        }
        return m <= 0;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        int lo = 1, hi = *max_element(bloomDay.begin(),bloomDay.end()), ans = -1;
        while(lo <= hi){
            int mid = lo + (hi - lo)/2;
            if(check(mid,bloomDay, m, k)){
                hi = mid - 1;
                ans = mid;
            }
            else lo = mid + 1;
        }
        return ans;
    }
};