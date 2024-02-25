git/*
 * @lc app=leetcode.cn id=2 lang=java
 *
 * [2] 两数相加
 */

// @lc code=start
/**
 * Definition for singly-linked list. public class ListNode { int val; ListNode
 * next; ListNode(int x) { val = x; } }
 */
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int tmp = 0;
        int sign = 1;
        ListNode l3 = l2;
        l2.val += l1.val; 
        if(l2.val >=10){
            tmp = l2.val / 10;
            l2.val = l2.val % 10;
        }
        while(tmp != 0 || sign == 1){
            sign = 1;
            if(l2.next == null){
                l2.next = new ListNode(0);
            }
            if(l1.next == null){
                l1.next = new ListNode(0);
            }
            l2.next.val += tmp;
            l2.next.val += l1.next.val;
            if(l2.next.val >= 10){
                tmp = l2.next.val / 10;
                l2.next.val = l2.next.val % 10;
            }else{
                tmp = 0;
            }
            l1 = l1.next;
            l2 = l2.next;
        }
        return l3;
    }
}
// @lc code=end
