// Last updated: 1/11/2026, 1:03:53 PM
class Solution {
    private:
    bool wildcard(int i, int j ,string &s, string &p, vector<vector<int>> &dp)
    {
        if(j < 0)
        {
            if(i >= 0) return false;
            else return true;
        }
        if(i < 0)
        {
            if(p[j] == '*')
            {
                while(j >= 0)
                {
                    if(p[j] != '*')
                    {
                        return false;
                    }
                    j--;
                }
                return true;
            }
            else return false;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(p[j] == '*')
        {
            return dp[i][j] = wildcard(i-1,j,s,p,dp) | wildcard(i,j-1,s,p,dp);
        }
        else
        {
            if(p[j] == '?' || p[j] == s[i])
            {
                return dp[i][j] = wildcard(i-1,j-1,s,p,dp);
            }
            else
            {
                return dp[i][j] = false;
            }
        }

    }
public:
    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return wildcard(n-1,m-1,s,p,dp);
    }
};