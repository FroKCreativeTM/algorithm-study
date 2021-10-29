class Solution:
    def merge(self, intervals: List[List[int]]) -> List[List[int]]:
        merged = []
        
        for i in sorted(intervals, key=lambda x: x[0]) :
            # 만약 merged 안에 내용물이 있고
            # 그 내용물의 마지막이 더 크다면
            if merged and i[0] <= merged[-1][1] : 
                merged[-1][1] = max(merged[-1][1], i[1])
            else : 
                # i, 
                # 중첩 리스트로 만드는 문법
                # 이게 없다면 단순히 list안의 내용물만 들어간다.
                merged += i,
                
        return merged