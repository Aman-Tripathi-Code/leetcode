// Last updated: 1/11/2026, 1:02:43 PM
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *head1, ListNode *head2) {
        if(!head1||!head2){
            return NULL;
        }
        ListNode* tempA = head1;
        ListNode* tempB = head2;
        while(tempA!=tempB){
            if(tempA == NULL){
                tempA = head2;
            }
            else{
                tempA = tempA->next;
            }
            if(tempB == NULL){
                tempB = head1;
            }
            else{
                tempB = tempB->next;
            }
            
            // cout << tempA->val << "  " << tempB->val << endl;
            
            if(tempA==tempB){
                return tempA;
            }
        }
        return tempA;
    }
};