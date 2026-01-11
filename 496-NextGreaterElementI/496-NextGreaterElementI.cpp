// Last updated: 1/11/2026, 1:01:40 PM
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums, vector<int>& arr) {
        vector<int> ans;
        vector<long long> nge;
        stack<long long> st;
        int n = arr.size();
        unordered_map<int,int> mp;
        for(int i= n-1; i>=0; i--){
            while(!st.empty() && arr[i] >= st.top()){
                st.pop();
            }
            if(st.empty()){
                nge.push_back(-1);
            }
            else{
                nge.push_back(st.top());
            }
            mp[arr[i]] = i;
            st.push(arr[i]);
        }
        reverse(nge.begin(),nge.end());
        for(auto x:nums){
            ans.push_back(nge[mp[x]]);
        }
        return ans;
    }
};