// Last updated: 1/11/2026, 1:03:28 PM
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
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return NULL;
        ListNode* ptr = head;
        while(ptr->next!=NULL){
            if(ptr->val == ptr->next->val){
                ListNode* temp = ptr;
                while(temp->next!=NULL && temp->val == temp->next->val){
                    temp = temp->next;
                }
                ptr ->next = temp->next;
                ptr  = temp;
            }
            else ptr = ptr->next;
        }
        return head;
    }
};