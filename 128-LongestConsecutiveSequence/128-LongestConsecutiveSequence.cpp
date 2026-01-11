// Last updated: 1/11/2026, 1:03:00 PM
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        int n = nums.size();
        if(nums.size()==0){
            return 0;
        }
        int maxi = 0;
        unordered_set<int> st;
        for(int i = 0;i<n;i++){
            st.insert(nums[i]);
        }
        for(int i = 0;i<n; i++){
            if(st.find(nums[i]-1)!=st.end()){
                continue;
            }
            else{
                int curr = nums[i], cnt = 0;
                while(st.find(curr)!=st.end()){
                    cnt++;
                    curr++;
                }
                maxi = max(maxi,cnt);
            }
        }
        return maxi;
    }
};