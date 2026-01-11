// Last updated: 1/11/2026, 1:00:31 PM
class Solution {
private:
    bool isPossible(long long x, long long k, vector<int>& candies){
        int n = candies.size();
        long long numOfChildren = 0;
        for(int i = 0; i<n; i++){
            numOfChildren += candies[i]/x;
        }
        return (numOfChildren >= k);
    }
public:
    int maximumCandies(vector<int>& candies, long long k) {
        int minEle = *min_element(candies.begin(),candies.end());
        long long lo = 0 , hi = 1e9;
        while(hi - lo > 1){
            int mid = lo + (hi - lo)/2;
            if(isPossible(mid,k,candies)){
                lo = mid;
            }
            else hi = mid;
        }
        return lo;
    }
};