// Last updated: 1/11/2026, 1:00:43 PM
class Solution {
    private:
    bool check(vector<int> &weights,int days, int x){
        int sum = 0, cnt = 0;
        for(int i = 0; i<weights.size(); i++){
            if(weights[i] <= x - sum){
                sum += weights[i];
            }
            else if(x < weights[i]) return false;
            else{
                sum = weights[i];
                cnt++;
            }
        }
        cnt++;
        if(cnt <= days) return true;
        return false;
    }
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = 0, hi = 1e8;
        while(hi - lo > 1){
            int mid = lo + (hi - lo)/2;
            if(!check(weights,days,mid)){
                lo =  mid;
            }
            else{
                hi = mid;
            }
        }
        return hi;
    }
};