// Last updated: 1/11/2026, 1:00:34 PM
class Solution {
private:
    int LCS(int i, int j , string text1, string text2){
        
        if(i<0||j<0){
            return 0;
        }
        
        //matches 
        if(text1[i]==text2[j]){
                return 1 + LCS(i-1,j-1,text1,text2);
        }

        //not matches
        return max(LCS(i-1,j,text1,text2) ,LCS(i,j-1,text1,text2));
    }
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1 = text1.size(), n2 = text2.size();
        //dp state will represent the max length of common subseq in s1 and s2 from ith index in s1 and from jth
        //index in s2
        vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));

        for(int i= 1; i<=n1; i++){
            for(int j =1 ; j<=n2; j++){
                if(text1[i-1]==text2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
                
            }
        }
        // for(int i = 0; i<=n1; i++){
        //     for(int j = 0;j<=n2; j++){
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }
        return dp[n1][n2];
    }
};