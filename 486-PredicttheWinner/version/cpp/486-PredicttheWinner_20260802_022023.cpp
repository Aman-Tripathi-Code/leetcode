// Last updated: 8/2/2026, 2:20:23 AM
1class Solution {
2public:
3    int dp[21][21]={};
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
20    
21    bool predictTheWinner(vector<int>& nums) {
22        
23        int n = nums.size();
24        memset(dp,-1,sizeof(dp));
25
26		return takeStone(true,0,n-1,nums) >= 0; 
27    }
28};