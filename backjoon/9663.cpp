#include <iostream>
#include <vector>
#include <ctime>

using namespace std;

int board[15];
long long answer = 0;
int n;

// 1번째 row부터 nRow번째 row까지 체크한다.
bool IsCorrectBoard(int nRow)
{
    for(int i = 0; i < nRow; ++i)
    {
        // 가로가 같거나, 세로가 같거나, 대각선에 위치한 경우
        if(i == nRow || board[i] == board[nRow] || abs(board[nRow] - board[i]) == nRow - i)
            return false;
    }
    return true;
}

void dfs(int level)
{
    // 만약 마지막까지 통과과 된 경우
    if(level == n)
    {
        answer++;
    }
    else
    {
        for(int i = 0; i < n; i++)
        {
            board[level] = i;                               // 해당 위치에 퀸을 배치
            if(IsCorrectBoard(level))    // 유효하다면 다음행의 퀸 배치, 유효하지않다면 다른 위치로 퀸 배치 변경
                dfs(level + 1);
        }
    }
}

void solution(int n)
{
    // 먼저 key값이 row, value 값이 col
    dfs(0);
    cout << answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> n;
    //time_t start, end;
    //start = time(NULL);
    solution(n);
    //end = time(NULL);
    //cout << "time : " << (double)(end - start) << endl;
    return 0;
}