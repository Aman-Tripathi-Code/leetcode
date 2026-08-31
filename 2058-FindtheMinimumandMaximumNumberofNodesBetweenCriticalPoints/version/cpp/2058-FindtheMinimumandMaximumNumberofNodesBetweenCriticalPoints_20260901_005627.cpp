// Last updated: 9/1/2026, 12:56:27 AM
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
13    bool isCritical(int left, int mid, int right){
14        return (left > mid && right > mid) || (mid > left && mid > right);
15    }
16    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
17        vector<int> ans;
18        ListNode* pre = head;
19        ListNode* curr = head->next;
20        int firstInd = -1, currInd = 1, preInd = -1;
21        int maxi = -1, mini = 1e9;
22        while(curr->next != nullptr){
23            if(isCritical(pre->val, curr->val, curr->next->val)){
24                if(firstInd == -1) firstInd = currInd;
25                else maxi = currInd - firstInd;
26                if(preInd != -1){
27                    mini = min(mini,currInd - preInd);
28                }
29                preInd = currInd;
30            }
31            pre = pre->next;
32            curr = curr->next;
33            currInd++;
34        }
35        if(mini == 1e9) mini = -1;
36        return {mini, maxi};
37    }
38};