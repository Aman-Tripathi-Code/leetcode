// Last updated: 7/23/2026, 12:11:35 PM
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
13    ListNode* reverseList(ListNode* head) {
14        if(head == nullptr) return head;
15        ListNode* front = head;
16        ListNode* prev = nullptr;
17        ListNode* ptr = head;
18        while(ptr != nullptr){
19            front = ptr->next;
20            ptr->next = prev;
21            prev = ptr;
22            ptr = front;
23        }
24        return prev;
25    }
26};