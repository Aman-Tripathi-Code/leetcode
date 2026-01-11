// Last updated: 1/11/2026, 1:00:37 PM
class Solution {
private:
    bool compare(string s1, string s2){
        int n1 = s1.size(), n2 = s2.size();
        if(abs(n1-n2)!=1){
            return false;
        }
        int i = 0, j = 0;
        while(i<n1){
            if(j<n2 && s1[i]==s2[j]){
                i++;
                j++;
            }
            else{
                i++;
            }
        }
        if(j==n2&&i==n1){
            return true;
        }
        return false;
    }
    static bool cmp(string s1,string s2){
        return s1.size()<s2.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(),words.end(),cmp);
        int n = words.size();
        vector<int> dp(n,1);
        int maxLen = 1;
        for(int i = 1;i<n ; i++){
            for(int j = 0; j<i; j++){
                if(compare(words[i],words[j]) && dp[j]+1>dp[i]){
                    dp[i] = dp[j] + 1;
                }
            }
            if(dp[i]>maxLen){
                maxLen = dp[i];
            }
        }
        for(auto it:dp){
            cout << it << " ";
        }
        return maxLen;
    }
};