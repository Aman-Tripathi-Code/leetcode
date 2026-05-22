// Last updated: 5/22/2026, 1:53:58 PM
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
13    int len(ListNode* head, int k, int &ele){
14        int cnt = 0;
15        ListNode* ptr = head;
16        while(ptr){
17            cnt++;
18            if(cnt == k) ele = ptr->val;
19            ptr = ptr->next;
20        }
21        return cnt;
22    }
23    int findElem(ListNode* head, int k , int n){
24        ListNode* ptr = head;
25        int cnt = 0;
26        while(ptr){
27            cnt++;
28            if(cnt == (n-k+1)) return ptr->val;
29            ptr = ptr->next;
30        }
31        return -1;
32    }
33    ListNode* swapNodes(ListNode* head, int k) {
34        int kthElem = 0;
35        int n = len(head, k, kthElem);
36        int kthElemFromLast = findElem(head,k,n);
37        ListNode* ptr = head;
38        for(int i = 0; i<n; i++){
39            if(i == k-1){
40                ptr->val = kthElemFromLast;
41            }
42            if(i == (n-k)){
43                ptr->val = kthElem;
44            }
45            ptr = ptr->next;
46        }
47        return head;
48    }
49};