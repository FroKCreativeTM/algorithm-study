import collections

class Solution:
    def solution(n, queries) :
        answer = []

        queses = []
        # -100000~100000
        front = -100001

        for _ in range(0, n) : 
            queses.append(collections.deque())

        for query in queries : 
            # pop
            if query[0] == -1 : 
                if front = -100001 : 
                    continue
                    
                else : 
                    answer.append(front)

                    