# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    length : int = 0
    def diameterOfBinaryTree(self, root: Optional[TreeNode]) -> int:
        def dfs(node : TreeNode) -> int : 
            if not node : 
                return -1
            
            # 왼쪽과 오른쪽으로 퍼져가면서 찾아본다.
            left = dfs(node.left)
            right = dfs(node.right)
            
            # 가장 긴 length를 탐색한다.
            self.length = max(self.length, left + right + 2)
            
            # 상태값을 반환한다.
            return max(left, right) + 1
        
        dfs(root)
        return self.length