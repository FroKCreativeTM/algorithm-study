class Solution:
    def permute(self, nums: List[int]) -> List[List[int]]:
        answer = []
        leaf = []
        def dfs(elements) :
            if len(elements) == 0 : 
                answer.append(leaf[:])
                
            # 순열 생성 재귀 호출
            for i in elements : 
                next_elements = elements[:]
                next_elements.remove(i)
                
                leaf.append(i)
                dfs(next_elements) 
                leaf.pop()
                
                
        dfs(nums)
        return answer;
        