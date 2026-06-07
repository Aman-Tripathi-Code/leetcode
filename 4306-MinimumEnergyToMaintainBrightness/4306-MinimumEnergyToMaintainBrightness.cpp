// Last updated: 6/8/2026, 2:07:26 AM
class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {
        int bulbs = ceil((brightness*1.0)/3);

        sort(intervals.begin(),intervals.end());

        long long totalTime = 0;
        int left = intervals[0][0], right = intervals[0][1];
        int m = intervals.size();

        for(int i = 1; i<m; i++){
            if(intervals[i][0] <= right){
                right = max(right,intervals[i][1]);
            }else{
                totalTime += 1LL*(right - left + 1);
                left = intervals[i][0];
                right = intervals[i][1];
            }
        }

        totalTime += 1LL*(right - left + 1);
        return (totalTime * bulbs); 
        
    }
};