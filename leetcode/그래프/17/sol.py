class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        def dfs(idx, path) : 
            # 만약 각 output에 들어갈 path가
            # digits의 길이와 같으면 answer에 넣어준다.
            # 즉 끝까지 탐색이 완료된 경우면 answer에 넣어주고 백트래킹한다.
            if len(path) == len(digits) : 
                answer.append(path)
                return
            
            # 입력값 자릿수 단위로 이를 반복한다.
            for i in range(idx, len(digits)) :
                # 각 숫자에 해당하는 모든 문자열을 반복한다.
                for j in dic[digits[i]] : 
                    dfs(i + 1, path + j)
                    
                    
        # 예외처리
        if not digits : 
            return []
        
        dic = {"2" : "abc",
              "3" : "def",
              "4" : "ghi",
              "5" : "jkl",
              "6" : "mno",
              "7" : "pqrs",
              "8" : "tuv", 
              "9" : "wxyz"}
        
        answer = []
        dfs(0, "")
        
        return answer