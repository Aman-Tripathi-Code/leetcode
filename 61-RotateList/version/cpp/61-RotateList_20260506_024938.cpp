// Last updated: 5/6/2026, 2:49:38 AM
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
13    ListNode* rotateRight(ListNode* head, int k) {
14        if(head == nullptr || k == 0) return head;
15        int len = 1;
16        ListNode* ptr = head;
17        while(ptr->next){
18            len++;
19            ptr = ptr -> next;
20        }
21        ptr->next = head;
22        int shift = len - (k % len);
23        while(shift--){
24            ptr = ptr->next;
25        }
26        head = ptr->next;
27        ptr->next = nullptr;
28        return head;
29    }
30};