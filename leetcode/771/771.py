class Solution:
    def numJewelsInStones(self, jewels: str, stones: str) -> int:
        freqs = {}
        cnt = 0
        
        for char in stones : 
            if char not in freqs : 
                freqs[char] = 1
            else : 
                freqs[char] += 1
                
        for char in jewels : 
            if char in freqs : 
                cnt += freqs[char]
                
        return cnt