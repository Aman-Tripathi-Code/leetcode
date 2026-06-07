// Last updated: 6/8/2026, 2:07:29 AM
class Solution {
public:
    int findWaviness(int n){
        string s = to_string(n);
        int len = s.length(), cnt = 0;
        if(len < 3) return 0;
        for(int i = 1; i<len-1; i++){
            if((s[i] > s[i-1] && s[i] > s[i+1]) || (s[i] < s[i-1] && s[i] < s[i+1])){
                cnt++;
            } 
        }
        return cnt;
    }
    int totalWaviness(int num1, int num2) {
        int waviness = 0;
        for(int i = num1; i<=num2; i++){
            waviness += findWaviness(i);
        }
        return waviness;
    }
};

