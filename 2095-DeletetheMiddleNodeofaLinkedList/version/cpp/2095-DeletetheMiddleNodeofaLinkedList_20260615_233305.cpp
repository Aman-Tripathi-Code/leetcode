// Last updated: 6/15/2026, 11:33:05 PM
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
13    ListNode* deleteMiddle(ListNode* head) {
14        if(head->next == nullptr) return nullptr;
15        ListNode* slow = head;
16        ListNode* fast = head;
17        ListNode* preSlow = new ListNode(0);
18        preSlow->next = head;
19        while(fast != nullptr && fast -> next != nullptr){
20            fast = fast -> next -> next;
21            slow = slow -> next;
22            preSlow = preSlow -> next;
23        }
24
25        preSlow->next = slow->next;
26        return head;
27    }
28};