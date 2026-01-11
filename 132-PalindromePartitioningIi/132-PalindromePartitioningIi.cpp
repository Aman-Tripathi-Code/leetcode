// Last updated: 1/11/2026, 1:02:57 PM
class Solution {
private:
    bool isPalindrome(string &s, int start, int end){
        while(start<end){
            if(s[start]!=s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    int recursion(int ind, string &s, int n,vector<int> &dp){
        if(ind==n){
            return 0;
        }
        if(dp[ind]!=-1){
            return dp[ind];
        }
        dp[ind] =  1e9;
        for(int j = ind; j<n; j++){
            if(isPalindrome(s,ind,j)){
                int cost = 1 + recursion(j+1,s,n,dp);
                dp[ind] = min(cost,dp[ind]);
            }
        }
        return dp[ind];
    }
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> dp(n,-1);
        return recursion(0,s,n,dp)-1;
    }
};