// Last updated: 7/1/2026, 1:56:06 PM
1/**
2 * Definition for singly-linked list.
3 * public class ListNode {
4 *     int val;
5 *     ListNode next;
6 *     ListNode() {}
7 *     ListNode(int val) { this.val = val; }
8 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
9 * }
10 */
11class Solution {
12    public ListNode reverseList(ListNode head) {
13        if(head == null || head.next == null) return head;
14
15        ListNode newHead = reverseList(head.next);
16        ListNode front = head.next;
17        front.next = head;
18        head.next = null;
19        return newHead;
20    }
21}