from typing import Collection, Deque


class Solution:
    def isPalindrome(self, s: str) -> bool:
        # 자료형 데크로 선언
        strs : Deque = collection.deque()

        for char in s : 
            if char.isalnum() : 
                strs.append(char.lower())

        while len(strs) > 1 : 
            if strs.popleft() != strs.pop() : 
                return False

        return True