// Last updated: 1/11/2026, 12:59:19 PM
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        set<int> st;
        for(auto &it: nums){
            if(st.find(it) != st.end()){
                ans.push_back(it);
            }
            st.insert(it);
        }
        return ans;
    }
};