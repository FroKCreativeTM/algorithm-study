class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        HashMap<Character, Integer> hm = new HashMap<>();
        int cnt = 0;
        
        for(char c : stones.toCharArray()) {
            Integer i = hm.get(c);
            if(i == null) {
                hm.put(c, 1);
            } else {
                hm.replace(c, i, i + 1);
            }
        }
        
        for(char c : jewels.toCharArray()) {
            Integer i = hm.get(c);
            if(i != null) {
                cnt += i;
            } 
        }
        
        return cnt;
    }
}