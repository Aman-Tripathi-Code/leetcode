// Last updated: 7/1/2026, 12:49:37 AM
1class Solution {
2    public boolean isValid(String s) {
3        Map<Character,Integer> charMap = new HashMap<>();
4        charMap.put('(',1);
5        charMap.put(')',-1);
6        charMap.put('{',2);
7        charMap.put('}',-2);
8        charMap.put('[',3);
9        charMap.put(']',-3);
10
11        Deque<Integer> st = new ArrayDeque<>();
12        int n = s.length();
13
14        for(int i = 0; i<n; i++){
15            int val = charMap.get(s.charAt(i));
16
17            if(val > 0){
18                st.push(val);
19            }else{
20                if(!st.isEmpty() && st.peek() + val == 0){
21                    st.pop();
22                }else{
23                    return false;
24                }
25            }
26        }
27        if(!st.isEmpty()) return false;
28        return true;
29    }
30}