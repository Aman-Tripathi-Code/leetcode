// Last updated: 1/11/2026, 12:59:24 PM
class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int totalApple = accumulate(apple.begin(),apple.end(),0);
        sort(capacity.begin(),capacity.end(),greater<int>());
        int i = 0, m = capacity.size();
        while(totalApple > 0){
            totalApple -= capacity[i++];
        }
        return i;
    }
};