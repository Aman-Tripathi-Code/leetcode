// Last updated: 6/14/2026, 12:22:30 AM
1/**
2 * Definition for singly-linked list.
3 * struct ListNode {
4 *     int val;
5 *     ListNode *next;
6 *     ListNode() : val(0), next(nullptr) {}
7 *     ListNode(int x) : val(x), next(nullptr) {}
8 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
9 * };
10 */
11class Solution {
12public:
13    int pairSum(ListNode* head) {
14        stack<int> st;
15        ListNode* ptr = head;
16        while(ptr){
17            st.push(ptr->val);
18            ptr = ptr->next;
19        }
20        int maxi = 0;
21        ptr = head;
22        while(ptr){
23            int curr = ptr->val + st.top();
24            st.pop();
25            ptr = ptr->next;
26            maxi = max(maxi,curr);
27        }
28        return maxi;
29    }
30};