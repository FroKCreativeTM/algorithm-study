class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        INFINITY : int = 2147483647
        cost = [INFINITY for _ in range(n)]
        cost[src] = 0

        for i in range(K + 1):
            tmp = list(cost)
            for p in flights:
                tmp[p[1]] = min(tmp[p[1]], cost[p[0]] + p[2])
            cost = tmp

        return -1 if cost[dst] >= 1e9 else cost[dst]
