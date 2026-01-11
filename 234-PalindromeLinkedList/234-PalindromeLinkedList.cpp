// Last updated: 1/11/2026, 1:02:16 PM
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
private:
    ListNode* reverseLL(ListNode* head){
        ListNode* dummy = NULL;
        while(head!=NULL){
            ListNode* nextPointer = head->next;
            head->next = dummy;
            dummy = head;
            head = nextPointer;
        }
        return dummy;
    }
public:
    bool isPalindrome(ListNode* head) {
        int len = 0;
        ListNode* ptr = head;
        while(ptr!=NULL){
            len++;
            ptr = ptr->next;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next!=NULL&&fast->next->next!=NULL){
            fast = fast->next->next;
            slow = slow->next;
        }
        slow = slow->next;
        slow = reverseLL(slow);
    
        for(int i = 0; i<len/2; i++){
            if(head->val!=slow->val){
                return false;
            }
            head = head->next;
            slow = slow->next;
        }
        return true;
    }
};