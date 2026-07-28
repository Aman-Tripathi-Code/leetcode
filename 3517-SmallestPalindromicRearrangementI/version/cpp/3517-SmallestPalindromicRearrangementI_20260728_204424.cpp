// Last updated: 7/28/2026, 8:44:24 PM
class Solution {
public:
    string smallestPalindrome(string s) {
        int n = s.size();
        int counts[26] = {0};
        
        // 1. O(N) 統計頻率
        for(int i = 0; i < n / 2; ++i) {
            counts[s[i] - 'a']++;
        }
        
        // 2. O(N) 原地重建前半段
        int idx = 0;
        for(int i = 0; i < 26; ++i) {
            while(counts[i]-- > 0) {
                s[idx++] = (char)(i + 'a');
            }
        }
        
        // 3. O(N) 鏡像複製到後半段
        for(int i = 0; i < n / 2; ++i) {
            s[n - 1 - i] = s[i];
        }
        
        return s;
    }
};