class Solution {
    public int arrayPairSum(int[] nums) {
        int sum = 0;
        ArrayList<Integer> pair = new ArrayList<Integer>();
        Arrays.sort(nums);
        
        for(int i : nums) {
            pair.add(i);
            
            if(pair.size() == 2) {
                sum += Collections.min(pair);
                pair = new ArrayList<Integer>();
            }
        }
        
        return sum;
    }
}