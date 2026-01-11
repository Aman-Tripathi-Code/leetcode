// Last updated: 1/11/2026, 1:03:27 PM
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int> rightSmaller(n);
        stack<int> st;
        for(int i = n-1; i>=0; i--){

            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                rightSmaller[i] = n-1;
            }
            else{
                rightSmaller[i] = st.top()-1;
            }
            st.push(i);
        }
        while(!st.empty()){
            st.pop();
        }
        vector<int> leftSmaller(n);
        for(int i = 0; i<n; i++){
            while(!st.empty() && heights[i]<=heights[st.top()]){
                st.pop();
            }
            if(st.empty()){
                leftSmaller[i] = 0;
            }
            else{
                leftSmaller[i] = st.top()+1;
            }
            st.push(i);
        }
        for(auto it:leftSmaller){
            cout << it << " ";
        }
        cout << endl;
        for(auto it:rightSmaller){
            cout << it << " ";
        }
        
        
        vector<int> ans(n);
        int maxi = -1e9;
        for(int i = 0; i<n; i++){
            int width = abs(rightSmaller[i]-leftSmaller[i]+1);
            ans[i] = heights[i] * width;
            maxi = max(ans[i],maxi);
        }
        return maxi;
        
    }
};