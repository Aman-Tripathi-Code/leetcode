// Last updated: 1/11/2026, 1:04:08 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* start = new ListNode();
        start->next = head;

        if(head==NULL){
            return NULL;
        }
        ListNode* fast = start;
        for(int i = 0; i<n; i++){
            fast = fast->next;
        }
        ListNode* slow = start;
        while(fast->next!=NULL){
            fast = fast -> next;
            slow = slow -> next;
        }

        slow->next = slow->next->next;

        return start->next;
    }
};