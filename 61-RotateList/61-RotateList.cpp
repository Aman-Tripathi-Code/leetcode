// Last updated: 1/11/2026, 1:03:44 PM
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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0) return head;
        ListNode* ptr = head;
        int len = 1;
        while(ptr->next){
            ptr = ptr->next;
            len++;
        }
        ptr->next = head;
        int counter = len-(k%len);
        while(counter--){
            ptr = ptr->next;
        }
        head = ptr->next;
        ptr->next = NULL;
        return head;
    }
};
