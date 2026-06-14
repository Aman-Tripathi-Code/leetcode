// Last updated: 6/15/2026, 2:33:58 AM
1class Solution {
2    public int[] asteroidCollision(int[] asteroids) {
3        Stack<Integer> st = new Stack<Integer>();
4        int n = asteroids.length;
5        for(int i = 0; i<n; i++){
6            if(asteroids[i] > 0){
7                st.push(asteroids[i]);
8            }else{
9                while(!st.empty() && Math.abs(asteroids[i]) > st.peek() && st.peek() > 0){
10                    st.pop();
11                }
12                if(!st.empty() && st.peek() == Math.abs(asteroids[i])){
13                    st.pop();
14                }else if(st.empty() || st.peek() < 0){
15                    st.push(asteroids[i]);
16                }
17            }
18        }
19        int []ans = new int[st.size()];
20        for(int i = st.size()-1; i>=0; i--){
21            ans[i] = st.peek();
22            st.pop();
23        }
24        return ans;
25
26    }
27}