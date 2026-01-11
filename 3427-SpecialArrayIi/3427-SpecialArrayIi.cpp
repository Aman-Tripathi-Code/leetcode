// Last updated: 1/11/2026, 12:59:23 PM
class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        vector<bool> ans;
        int n = nums.size();
        vector<int> par(n);
        par[0] = -1;
        for(int i = 1; i<n; i++){
            if((nums[i] ^ nums[i-1]) & 1){
                par[i] = par[i-1];
            }
            else par[i] = i;
        }
        for(auto &it : par) cout << it << ' ';
        for(auto &q : queries){
            int start = q[0], end = q[1];
            int key = par[end];
            bool flag = false;
            start++;
            while(start <= end){
                int mid = start + (end - start)/2;
                if(mid == key){
                    flag = true;
                    break;
                }
                else if(mid < key) start = mid + 1;
                else end = mid - 1;
            }
            (flag) ? ans.push_back(false) : ans.push_back(true);
        }
        return ans;
    }
};