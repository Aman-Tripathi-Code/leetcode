// Last updated: 1/11/2026, 1:01:16 PM
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n = temperatures.size();
        vector<int> nge(n);
        for(int i = n-1; i>=0; i--){
            while(!st.empty() && temperatures[i]>=temperatures[st.top()]){
                st.pop();
            }
            if(st.empty()){
                nge[i] = 0;
            }
            else{
                nge[i] = st.top()-i;
            }
            st.push(i);
        }
        return nge;
    }
};