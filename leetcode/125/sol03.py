class Solution:
    def isPalindrome(self, s: str) -> bool:
        # 먼저 모든 대문자를 소문자로 바꾼뒤
        s = s.lower()
        # 필요한 문자열 빼고 전부 지운다
        s = re.sub('[^a-z0-9]', '', s)
        
        # 이후 앞과 뒤를 순차적으로 돌면서 펠린드롬 여부를 확인한다.
        return s == s[::-1]