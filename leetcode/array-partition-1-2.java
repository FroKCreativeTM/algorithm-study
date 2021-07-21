class Solution {
    public int arrayPairSum(int[] nums) {
        int sum = 0;
        Arrays.sort(nums);
        
        for(int i = 0; i < nums.length; ++i) {
            // 짝수 번째 값의 합을 계산한다.
            if(i % 2 == 0) {
                sum += nums[i];
            }
        }
        
        return sum;
    }
}