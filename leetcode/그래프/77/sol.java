// 46번(순열) 문제와 77번(조합) 문제는 직접적인 출제는 하지 않지만 굉장히 
// 자주 쓰이는 알고리즘 타입이다

// 그렇기 때문에 정확하게 알고 갈 필요가 있다.

class Solution {
    List<List<Integer>> answer = new ArrayList<>();
    
    int n;
    
    public void dfs(List<Integer> elements, int start, int k) {
        // 만약 더 이상 조합을 선택하지 않아도 된다면 answer에 넣어준다.
        if(k == 0) {
            List<Integer> temp = new ArrayList<>(elements);
            answer.add(temp);
        }
        
        // 모든 조합을 백트래킹을 이용해서 구한다.
        for(int i = start; i < n + 1; ++i) {
            elements.add(i);
            dfs(elements, i + 1, k - 1);
            elements.remove(elements.size() - 1);
        }
    }
    
    public List<List<Integer>> combine(int n, int k) {
        List<Integer> elements = new ArrayList<>();
        this.n = n;
        
        dfs(elements, 1, k);
        
        return answer;
    }
}