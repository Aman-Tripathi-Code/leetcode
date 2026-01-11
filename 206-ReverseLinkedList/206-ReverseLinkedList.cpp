// Last updated: 1/11/2026, 1:02:31 PM
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
    ListNode* reverseList(ListNode* head) {
        if(!head){
            return NULL;
        }
        ListNode* dummy = NULL;
        while(head!=NULL){
            ListNode* nextPointer = head->next;
            head->next = dummy;
            dummy = head;
            head = nextPointer;
        }
        return dummy;
    }
};