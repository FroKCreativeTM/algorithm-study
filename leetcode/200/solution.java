class Solution {
    int answer = 0;
    public void dfs(char[][] grid, int i, int j) {
        if(i < 0 ||
          i >= grid.length ||
          j < 0 ||
          j >= grid[0].length ||
          grid[i][j] != '1') {
            return;
        }
        
        // 방문 표시
        // 없으면 무한 루프
        grid[i][j] = 0;
        
        // 동서남북으로 이동
        dfs(grid, i + 1, j);
        dfs(grid, i - 1, j);
        dfs(grid, i, j + 1);
        dfs(grid, i, j - 1);
    }
    
    public int numIslands(char[][] grid) {
        for(int i = 0; i < grid.length; ++i) {
            for(int j = 0 ; j < grid[0].length; ++j) {
                if(grid[i][j] == '1') {
                    dfs(grid, i, j);
                    answer++;
                }
            }
        }
        
        return answer;
    }
}