// Last updated: 1/11/2026, 1:01:13 PM
class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int lo = -1, hi = n;
        while(hi-lo > 1){
            int mid = lo + (hi-lo)/2;
            if(letters[mid]<=target) lo = mid;
            else hi = mid;
        }
        if(lo == -1 || hi == n) return letters[0];
        return letters[hi];
    }
};