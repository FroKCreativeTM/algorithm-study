#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Pos
{
    int y, x;

    Pos() : y(-1), x(-1) {}
    Pos(int _y, int _x) : y(_y), x(_x) {}
};

/* -------- D I C E --------- */
int dice[4][3] = {
    {-1, 2, -1},
    {4, 1, 3},
    {-1, 5, -1},
    {-1, 6, -1},
};

// 북서남동
int dy[4] = {-1, 0, 1 , 0};
int dx[4] = {0, -1, 0, 1};

// 이거 구현하는데 좀 고생좀 함
// 삼성은 이런 노가다 구현 문제 좋아하는듯... (카카오 문제가 위대한 이유)
void moveDice(int dir)
{
    int tmp;
    switch (dir)
    {
    case 0:
        /* 북 */
        tmp = dice[0][1];
        dice[0][1] = dice[1][1];
        dice[1][1]  = dice[2][1];
        dice[2][1] = dice[3][1];
        dice[3][1] = tmp;
        break;
    case 1:
        /* 서 */
        tmp = dice[1][0];
        dice[1][0] = dice[1][1];
        dice[1][1] =  dice[1][2];
        dice[1][2] = dice[3][1];
        dice[3][1] = tmp;
        break;
    case 2:
        /* 남 */
        tmp = dice[3][1];
        dice[3][1] = dice[2][1];
        dice[2][1]  = dice[1][1];
        dice[1][1] = dice[0][1];
        dice[0][1] = tmp;
        break;
    case 3:
        /* 동 */
        tmp = dice[1][2];
        dice[1][2] = dice[1][1];
        dice[1][1] =  dice[1][0];
        dice[1][0] = dice[3][1];
        dice[3][1] = tmp;
        break;
    }
}

bool IsInside(int y, int x, int maxY, int maxX) {
    return (y >= 0) && (y < maxY) && (x >= 0) && (x < maxX);
}

int get_score_bfs(vector<vector<int>>& map, int y, int x, int B)  
{
    queue<Pos> q;
    int C = 0;
    int maxY = map.size(), maxX = map[0].size();
    vector<vector<bool>> visited(maxY, vector<bool>(maxX, false));

    q.push(Pos(y, x));
    visited[y][x] = true;

    while(!q.empty())
    {
        Pos nowPos = q.front();
        q.pop();
        C++;

        for (size_t i = 0; i < 4; i++)
        {
            int ny = nowPos.y + dy[i];
            int nx = nowPos.x + dx[i];
           
            if(!IsInside(ny, nx, maxY, maxX) || visited[ny][nx]) 
                continue;
            if(map[ny][nx] == B)
            {
                visited[ny][nx] = true;
                q.push(Pos(ny, nx));
            }
        }
    }

    return C * B;
}

int solution(vector<vector<int>>& map, int moveCount) 
{
    int answer = 0;
    int maxY = map.size(), maxX = map[0].size();
    int dir = 3; // 북서남동 순으로 움직임 그리고 조건에 가장 처음에 주사위의 이동 방향은 동쪽이다. 란 게 존재
    Pos pos(0,0);
    
    for (size_t i = 0; i < moveCount; i++)
    {
        // 1. 주사위가 이동 방향으로 한 칸 굴러간다.
        int ny = pos.y + dy[dir];
        int nx = pos.x + dx[dir];

        // 만약, 이동 방향에 칸이 없다면, 이동 방향을 반대로 한 다음 한 칸 굴러간다.
        if(!IsInside(ny, nx, maxY, maxX)) 
        {
            dir = (dir + 2) % 4;
            ny = pos.y + dy[dir];
            nx = pos.x + dx[dir];
        }

        pos.x = nx;
        pos.y = ny;
        moveDice(dir);

        // 주사위가 도착한 칸 (x, y)에 대한 점수를 획득한다.
        // B는 짜피 연속적으로 주사위가 붙어있는 곳 값 구할 때 필요하니 미리 저장해둠
        int B = map[ny][nx];
        answer += get_score_bfs(map, ny, nx, B);

        // 주사위의 아랫면에 있는 정수 A와 주사위가 있는 칸 (x, y)에 있는 정수 B를 비교해 이동 방향을 결정한다.
        int A = dice[3][1];
        if  (A > B) { // A > B인 경우 이동 방향을 90도 시계 방향으로 회전시킨다.
            dir = (dir - 1) % 4;
            if(dir < 0) dir = 3;
        }
        else if (A < B) dir = (dir + 1) % 4;    // A < B인 경우 이동 방향을 90도 반시계 방향으로 회전시킨다.
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int R, C, moveCnt;

    cin >> R >> C >> moveCnt;

    vector<vector<int>> map(R, vector<int>(C, -1));

    for (int y = 0; y < R; y++)
    {
        for (int x = 0; x < C; x++)
        {
            cin >> map[y][x];
        }
    }
    
    cout << solution(map, moveCnt) << endl;

    return 0;
}