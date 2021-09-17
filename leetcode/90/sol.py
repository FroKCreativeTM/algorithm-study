class Solution:
    def subsetsWithDup(self, nums: List[int]) -> List[List[int]]:
        result = []
        
        def dfs(index, path) :
            path.sort()
            
            if result.count(path) >= 1 : 
                return
            
            result.append(path)
            
            for i in range(index, len(nums)) : 
                dfs(i + 1, path + [nums[i]])
                
        dfs(0, [])
        return result