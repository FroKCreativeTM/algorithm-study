class Solution:
    def isPalindrome(self, head: ListNode) -> bool:
        rev = None
        slow = fast = head
        
        # 러너 기법을 이용해서 역순 연결 리스트를 구성한다.
        # 러너 기법 : slow와 fast 노드를 두고, 하나는 하나씩 다른 한 노드는 두개씩 진행을 한다.
        # 이 때 이 방식의 장점은 병합 지점이나 중간 위치, 길이 등을 판별할 때 유용하게 사용할 수 있다.
        while fast and fast.next : 
            fast = fast.next.next
            rev, rev.next, slow = slow, rev, slow.next
            
        if fast : 
            slow = slow.next
            
        # 팰린드롬 여부 확인
        while rev and rev.val == slow.val : 
            slow, rev = slow.next, rev.next
            
        return not rev