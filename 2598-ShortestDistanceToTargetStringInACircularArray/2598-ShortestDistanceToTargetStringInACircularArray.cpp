// Last updated: 6/8/2026, 2:08:11 AM
class Solution {
public:
    int closestTarget(vector<string>& words, string target, int startIndex) {
        int n = words.size(), ans = 1e9;
        for(int i = startIndex; i<(n+startIndex); i++){
            if(words[i%n] == target){
                ans = min(ans,min((n-i+startIndex),(i-startIndex)));
            }
        }
        return (ans == 1e9) ? -1 : ans;
    }
};