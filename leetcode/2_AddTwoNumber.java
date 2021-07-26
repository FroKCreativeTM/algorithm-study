class Solution {    
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = new ListNode(0);
        ListNode root = head;
        int sum = 0;
        
        while(l1 != null || l2 != null || sum > 0) {
            if(l1 != null) {
                sum += l1.val;
                l1 = l1.next;
            } 
            
            if(l2 != null) {
                sum += l2.val;
                l2 = l2.next;
            }
            
            head.next = new ListNode(sum % 10);
            sum /= 10;
            
            head = head.next;
        }
        return root.next;
    }
}