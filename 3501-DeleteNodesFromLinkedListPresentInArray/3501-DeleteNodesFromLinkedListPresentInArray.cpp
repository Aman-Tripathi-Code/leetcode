// Last updated: 1/11/2026, 12:59:21 PM
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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ListNode* dummy = new ListNode(0);
        ListNode* newHead = dummy;
        sort(nums.begin(),nums.end());
        ListNode* ptr = head;
        while(ptr){
            if(!binary_search(nums.begin(),nums.end(),ptr->val)){
                dummy->next = ptr;
                dummy = dummy->next;
            }
            ptr = ptr->next;
        }
        dummy->next = nullptr;
        return newHead->next;
    }
};