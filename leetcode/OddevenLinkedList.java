class Solution {
    public ListNode oddEvenList(ListNode head) {
        if(head == null) {
            return null; 
        } 
        
        ListNode odd = head;
        ListNode even = head.next;
        ListNode even_head = head.next;
        
        while (even != null && even.next != null) {
            // 두 칸씩 건너 뛴다.
            odd.next = odd.next.next;
            even.next = even.next.next;
            
            odd = odd.next;
            even = even.next;
        }
        
        // 두 노드를 붙여준다.
        odd.next = even_head;
        
        return head;
    }
}