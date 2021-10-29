#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    stack<int> s;
    
    for(auto m : moves) {
        auto n = m - 1;
        
        for(int y = 0; y < board.size(); ++y) {
            if(board[y][n] != 0) {
                if(!s.empty() && s.top() == board[y][n]) {
                    s.pop();
                    answer += 2;
                } else {
                    s.push(board[y][n]);
                }
                board[y][n] = 0;
                break;
            }   
        }
    }
    
    return answer;
}