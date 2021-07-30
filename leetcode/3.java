class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == "") {
            return 0;
        }
        
        HashMap<Character, Integer> hm = new HashMap<>();
        int max_length = 0;
        int start = 0;
        
        // 투 포인트 방식을 이용해서 처리한다.
        for (int i = 0; i < s.length(); ++i) {
            Integer tmp = hm.get(s.charAt(i));
            
            if (tmp != null && start <= tmp) { // 이미 등장한 문자라면 start의 위치를 갱신한다.
                start = tmp + 1;
            } else {    // 등장하지 않았다면, 최대 부분 문자열 길이를 갱신한다.
                max_length = Math.max(max_length, i - start + 1);                
            }
            
            if(tmp == null) {
                hm.put(s.charAt(i), i);
            } else {
                hm.replace(s.charAt(i), i);
            }
        }
        
        return max_length;
    }
}