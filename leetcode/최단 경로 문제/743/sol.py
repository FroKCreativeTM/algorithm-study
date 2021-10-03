class Solution:
    def networkDelayTime(self, times: List[List[int]], n: int, k: int) -> int:
        graph = collections.defaultdict(list)
        
        for u, v, w in times : 
            graph[u].append((v, w))
            
        # 소요시간, 정점
        # 즉 시작점에서 정점까지 거리
        # 처음에는 k->k니까 0이다.
        Q = [(0, k)]
        dist = collections.defaultdict(int)
        
        while Q : 
            time, node = heapq.heappop(Q)
            # 만약 dist에 정점이 없다면
            if node not in dist : 
                # node의 dist로 time을 넣어준다.
                dist[node] = time
                # 모든 edge를 순회하며
                for v, w in graph[node] : 
                    #  총 시간을 구한다.
                    alt = time + w
                    # Q에 시간과 시작 vertex를 갱신한다.
                    heapq.heappush(Q, (alt, v))
                    
                    
        # 모든 노드의 최단 경로 존재를 판별한다.
        if len(dist) == n : 
            return max(dist.values())
        return -1
                    