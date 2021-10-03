class Solution {
    List<List<Integer>> answer = new ArrayList<>();
    List<Integer> leaf = new ArrayList<Integer>();
    
    public void dfs(List<Integer> elements) {
        if(elements.size() == 0) {
            System.out.println(leaf);
            
            List<Integer> temp = new ArrayList<>(leaf);
            
            answer.add(temp);
        }
        
        for(Integer i : elements) {
            List<Integer> next_element = new ArrayList<Integer>(elements);
            next_element.remove(i);
            
            leaf.add(i);
            dfs(next_element);
            leaf.remove(leaf.size() - 1);
        }
    }
    
    public List<List<Integer>> permute(int[] nums) {
        List<Integer> elements = new ArrayList<Integer>();
        
        for(int i : nums) {
            elements.add(i);
        }
        
        dfs(elements);
        
        return answer;
    }
}