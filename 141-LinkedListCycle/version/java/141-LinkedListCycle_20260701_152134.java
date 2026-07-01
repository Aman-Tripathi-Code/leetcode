// Last updated: 7/1/2026, 3:21:34 PM
1/**
2 * Definition for singly-linked list.
3 * class ListNode {
4 *     int val;
5 *     ListNode next;
6 *     ListNode(int x) {
7 *         val = x;
8 *         next = null;
9 *     }
10 * }
11 */
12public class Solution {
13    public boolean hasCycle(ListNode head) {
14        if(head == null) return false;
15        ListNode fast = head, slow = head;
16
17        while(fast != null && fast.next != null){
18            fast = fast.next.next;
19            slow = slow.next;
20
21            if(fast == slow) return true;
22        }
23        return false;
24    }
25}