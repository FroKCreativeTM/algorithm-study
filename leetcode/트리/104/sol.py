# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def maxDepth(self, root: Optional[TreeNode]) -> int:
        # BFS를 이용해서 Depth를 추정하자.
        # 재귀가 아닌 반복 구조를 이용해서 풀어볼 것이다.
        # 먼저 반복구조를 위한 queue를 선언하자.
        queue = collections.deque([root])
        depth = 0
        
        # 이후 큐가 빌때까지 반복을 진행한다.
        while queue :
            # 먼저 depth를 증가 시긴다
            depth += 1
            
            # 이후 큐에서 하나씩 꺼낸다.
            for _ in range(len(queue)) : 
                cur_root = queue.popleft()
                # 만약 자식 노드가 있다면
                # 먼저 왼쪽부터 큐에 넣는다
                if cur_root.left : 
                    queue.append(cur_root.left)
                # 다음 오른쪽 노드를 큐에 넣는다.
                if cur_root.right : 
                    queue.append(cur_root.right
                                 
            # 이후 자식 노드까지 전부 넣어졌다면
            # 다시 돌아가서 depth를 증가시킨다.
                                 
        # BFS를 이용해서 순회를 돌고 난다면
        # depth값이 구해진다.
        return depth
        