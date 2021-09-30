// 풀이는 파이썬 코드에 있습니다.
// 파이썬으로 스케치된 코드를 자바로 포팅했습니다.
class Solution {
    ArrayList<String> answer = new ArrayList<String>();
    HashMap<Character, String> hm = new HashMap<>(); 
    
    public void dfs(int idx, String digits, String path) {
        if(path.length() == digits.length()) {
            answer.add(path);
            return;
        }
        
        int len = digits.length();
        for (int i = idx; i < len; ++i) {
            String temp = hm.get(digits.toCharArray()[i]);
            for (Character c : temp.toCharArray()) {
                dfs(i + 1, digits, path + c);
            }
        } 
    }
    
    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0) {
            return answer;
        }
        
        hm.put('2', "abc");
        hm.put('3', "def");
        hm.put('4', "ghi");
        hm.put('5', "jkl");
        hm.put('6', "mno");
        hm.put('7', "pqrs");
        hm.put('8', "tuv");
        hm.put('9', "wxyz");
        
        dfs(0, digits, "");
        
        return answer;
    }
}