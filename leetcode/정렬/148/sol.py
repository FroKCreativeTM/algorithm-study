# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def sortList(self, head: Optional[ListNode]) -> Optional[ListNode]:
        cur = head        
        nums = [] # 배열을 활용한다
        
        while cur != None : 
            nums.append(cur.val)
            cur = cur.next
            
        nums.sort()
        
        cur = head
        for i in range(len(nums)) : 
            cur.val = nums[i]
            cur = cur.next
            
        return head