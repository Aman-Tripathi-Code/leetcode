// Last updated: 1/11/2026, 1:04:20 PM
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummyHead = new ListNode(0);
        ListNode* head = dummyHead;
        int carry = 0;
        while(l1 || l2 || carry){
            int x = (l1)?l1->val:0;
            int y = (l2)?l2->val:0;
            int sum = x+y+carry;
            carry = sum/10;
            sum = sum%10;
            head->next = new ListNode(sum);
            head = head->next;
            l1 = (l1)?l1->next:NULL;
            l2 = (l2)?l2->next:NULL;
        }
        return dummyHead->next;
    }
};