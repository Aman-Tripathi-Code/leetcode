// Last updated: 8/3/2026, 12:39:41 AM
1class Solution {
2public:
3    int dp[501][501]={};
4    
5    int takeStone(bool Player, int l, int h, vector<int>& nums)
6    {
7        if(l>h) return -1;
8        
9        if(l==h) return nums[l];
10        
11        if(dp[l][h]!=-1) return dp[l][h];
12        if(Player)    
13            dp[l][h] = max(nums[l]+takeStone(!Player,l+1,h,nums),nums[h]+takeStone(!Player,l,h-1,nums));
14
15        else
16            dp[l][h] = min(-nums[l]+takeStone(!Player,l+1,h,nums),-nums[h]+takeStone(!Player,l,h-1,nums));
17
18        return dp[l][h];
19    }
20    bool stoneGame(vector<int>& piles) {
21        int n = piles.size();
22        memset(dp,-1,sizeof(dp));
23
24		return takeStone(true,0,n-1,piles) >= 0; 
25    }
26};