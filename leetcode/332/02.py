class Solution:
    def findItinerary(self, tickets: List[List[str]]) -> List[str]:
        # 먼저 그래프를 구성하자
        # from to로 구성된다.
        graph = collections.defaultdict(list)
        
        # 그래프에 행선지를 넣는다.
        # 이 때 sorted를 이용하면 딱 한 번만 정렬해도 결과가 동일하다.
        # 만약 여기서 역순으로 정렬하면, 뒤에서 앞부터 꺼낼 필요가 없다. 
        for a, b  in sorted(tickets, reverse = True) : 
            graph[a].append(b)
        
        result = []
        # 이후 순회를 돌면서 하나씩 pop하면서 
        # pop()으로 재귀 호출하면서 모두 꺼내 결과에 추가하는 방식이다.
        def dfs(a) : 
            # 첫번째 값을 읽어서 어휘 순으로 방문한다.
            while graph[a] : 
                # 위에서 역순으로 정렬해서 O(1)로 최적화되었다.
                dfs(graph[a].pop())
            result.append(a)
            
        dfs("JFK")
        
        # 다시 뒤집어서 어휘 순으로 출력
        return result[::-1]