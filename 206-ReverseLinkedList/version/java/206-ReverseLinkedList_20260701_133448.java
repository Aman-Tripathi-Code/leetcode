// Last updated: 7/1/2026, 1:34:48 PM
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
13        if(head == null) return null;
14
15        ListNode curr = head;
16        ListNode front = head;
17
18        ListNode prev = null;
19
20        while(curr != null){
21            front = curr.next;
22            curr.next = prev;
23            prev = curr;
24            curr = front;
25        }
26        return prev;
27    }
28}