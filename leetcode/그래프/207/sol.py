class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        graph = collections.defaultdict(list)
        
        for a, b in prerequisites : 
            graph[a].append(b)
            
        # 중복을 검사하기 위한 set을 준비한다.
        traced = set()
        # 방문한 곳은 다시 방문하지 않기 위한 요소다.
        visited = set()
        
        # 이 dfs는 cycle이 생기는 그래프인가를 체크하는 함수이다.
        def dfs(i) : 
            if i in traced : 
                return False
            
            if i in visited : 
                return True
            
            traced.add(i)
            
            for b in graph[i] : 
                if not dfs(b) : 
                    return False
            traced.remove(i)
            visited.add(i)
                
            return True
            
        for a in list(graph) : 
            if not dfs(a) : 
                return False
            
        return True