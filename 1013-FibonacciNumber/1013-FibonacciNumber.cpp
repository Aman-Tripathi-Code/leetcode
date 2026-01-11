// Last updated: 1/11/2026, 1:00:51 PM
class Solution {
private:
    int fibo(int n, vector<int> &dp){
        if(n==1||n==0){
            return n;
        }
        if(dp[n]!=-1){
            return dp[n];
        }
        return dp[n] = fibo(n-1,dp) + fibo(n-2,dp);
    }
public:
    int fib(int n) {
        
        //                5
        //          4             3
        //      3       2       2    1
        //   2    1   1   0   1  0
        // 1   0   
        
        
        // if(n==1||n==0){
        //     return n;
        // }
        // return fib(n-1)+fib(n-2);
        
        
        //     int curr = 1 , prev = 0, ans = 0;
        //     for(int i = 0; i<n; i++){
        //         ans = prev + curr;
        //         prev = curr;
        //         curr = ans;
        //     }
        //     return prev;
        // }
    
   
        //     if(n<2){
        //         return n;
        //     }
        //     int dp[n+1];
        //     dp[0]= 0;
        //     dp[1] = 1;
        //     for(int i = 2; i<=n ; i++){
        //         dp[i]= dp[i-1]+dp[i-2];
        //     }
        //     return dp[n];    
        // }
        
    vector<int> dp(n+1,-1);
    return fibo(n,dp);
    }
    
};