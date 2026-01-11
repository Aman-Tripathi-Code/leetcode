// Last updated: 1/11/2026, 1:01:00 PM
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
    ListNode* middleNode(ListNode* head) {
        int cnt = 0;
        ListNode* ptr = head;
        while(ptr->next!=NULL){
            ptr = ptr->next;
            cnt++;
        }
        cnt = ceil(cnt/2.0);
        ListNode* temp = head;
        while(cnt){
            temp = temp->next;
            cnt--;
        }
        return temp;
    }
};