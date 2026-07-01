// Last updated: 7/1/2026, 4:32:26 PM
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
12    public ListNode mergeTwoLists(ListNode list1, ListNode list2) {
13        ListNode mergedList = new ListNode();
14        ListNode mergedListHead = mergedList;
15        ListNode list1Itr = list1, list2Itr = list2;
16
17        while (list1Itr != null && list2Itr != null) {
18            if (list1Itr.val < list2Itr.val) {
19                mergedList.next = list1Itr;
20                list1Itr = list1Itr.next;
21            } else {
22                mergedList.next = list2Itr;
23                list2Itr = list2Itr.next;
24            }
25            mergedList = mergedList.next;
26        }
27        if (list1Itr != null)
28            mergedList.next = list1Itr;
29        if (list2Itr != null)
30            mergedList.next = list2Itr;
31
32        return mergedListHead.next;
33    }
34}