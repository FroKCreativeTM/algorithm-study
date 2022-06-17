#include <iostream>
#include <vector>  

using namespace std;

int dy[4][10] = { { -1, 1, -1, 1, -1, 1, -2, 2, 0, 0 },
{ 0, 0, -1, -1, -2, -2, -1, -1, -3, -2},
{ -1, 1, -1, 1, -1, 1, -2, 2, 0, 0 },
{ 0, 0, 1, 1, 2, 2, 1, 1, 3, 2}  };

int dx[4][10] = { { 0, 0, 1, 1, 2, 2, 1, 1, 3, 2},
{-1, 1, -1, 1, -1, 1, -2, 2, 0, 0}, 
{ 0, 0, -1, -1, -2, -2, -1, -1, -3, -2},
 { -1, 1, -1, 1, -1, 1, -2, 2, 0, 0}};

int percent[9] = { 1, 1, 7, 7, 10, 10, 2, 2, 5 };

bool IsInside(int n, int row, int col) {
    return (row >= 0) && (row < n) && (col >= 0) && (col < n);
}

int MoveSand(vector<vector<int>>& board,
    int row, int col, int origRow, int origCol, int dir) {
    int outSand = 0;

    // 다음 자리에 모래가 없다면 치울 것이 없다.
    if (board[row][col] == 0) return 0;

    int sand = board[row][col];
    int tmp = sand;

    // 퍼센트에 따라서 모래들을 치우자
    for (int i = 0; i < 9; ++i) {
        int nx = origCol - dx[dir][i];
        int ny = origRow - dy[dir][i];
        int per = percent[i];
        int plus = (tmp * per) / 100;

        if (!IsInside(board.size(), ny, nx))
            outSand += plus;
        else
            board[ny][nx] += plus;

        sand -= plus;
    }
    int nx = origCol - dx[dir][9];
    int ny = origRow - dy[dir][9];

    // 맨 마지막 모래를 정리한다.
    if (!IsInside(board.size(), ny, nx))
        outSand += sand;
    else
        board[ny][nx] += sand;

    board[row][col] = 0;
    return outSand;
}

int solution(int n, vector<vector<int>>& board) {
    int answer = 0;

    int row = n / 2;
    int col = n / 2;
    int dir = 0;
    int canMoveCnt = 1;
    int origMoveCnt = 1;
    int cnt = 0;

    // 보드의 맨 처음으로 돌아오기 전까지
    while (!(row == 0 && col == 0)) {
        int nextRow = row;
        int nextCol = col;

        switch (dir) {
            // LEFT
        case 0:
            nextCol--;
            break;
            // DOWN
        case 1:
            nextRow++;
            break;
            // RIGHT
        case 2:
            nextCol++;
            break;
            // UP
        case 3:
            nextRow--;
            break;
        }

        answer += MoveSand(board, nextRow, nextCol, row, col, dir);
        row = nextRow;
        col = nextCol;
        canMoveCnt--;

        if (canMoveCnt == 0) {
            cnt++;
            if (cnt == 2) {
                origMoveCnt++;
                cnt = 0;
            }
            canMoveCnt = origMoveCnt;

            dir++;
            if (dir == 4) dir = 0;
        }
    }

    return answer;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    vector<vector<int>> board;

    cin >> n;

    for (int row = 0; row < n; ++row) {
        vector<int> v;
        for (int col = 0; col < n; ++col) {
            int num = 0;
            cin >> num;
            v.push_back(num);
        }
        board.push_back(v);
    }

    cout << solution(n, board) << endl;

    return 0;
}