#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
int answer = 0;
int N, M;

struct Pos
{
    int y, x;
    Pos(int _y, int _x) : y(_y), x(_x) {}
};

bool IsInside(int y, int x)
{
    return (y >= 0) && (y < N) &&
        (x >= 0) && (x < M);
}

// BFS를 쓰자!(DFS보다 빠르다.)
void VirusSpread(vector<vector<int>> labotary)
{
    vector<vector<int>> visited = labotary;
    queue<Pos> q;

    // 모든 바이러스들을 넣는다.
    for (size_t y = 0; y < N; y++)
        for (size_t x = 0; x < M; x++)
            if(visited[y][x] == 2)
                q.push(Pos(y, x));
    
    while (!q.empty())
    {
        auto curPos = q.front();
        q.pop();

        for (size_t i = 0; i < 4; i++)
        {
            int nx = curPos.x + dx[i];
            int ny = curPos.y + dy[i];

            if(!IsInside(ny, nx)) continue;

            if(visited[ny][nx] == 0) 
            {
                visited[ny][nx] = 2;
                q.push(Pos(ny, nx));
            }
        }
    }
    
    int spreadCnt = 0;
    for (size_t y = 0; y < N; y++)
    {
        for (size_t x = 0; x < M; x++)
        {
            if(visited[y][x] == 0)
                spreadCnt++;
        }
    }

    answer = max(answer, spreadCnt);
}

void BuildWall(vector<vector<int>> labotary,
    int cnt)
{
    // 벽을 모두 세웠다면?
    // 바이러스를 퍼트려본다.
    if(cnt == 3)
    {
        VirusSpread(labotary);
    }
    else
    {
        for (size_t y = 0; y < N; y++)
        {
            for (size_t x = 0; x < M; x++)
            {
                if(labotary[y][x] == 0)
                {
                    labotary[y][x] = 1;  // 벽을 세운다.
                    BuildWall(labotary, cnt + 1);
                    labotary[y][x] = 0;
                }
            }
        }
    }
}

// 0 : 빈칸
// 1 : 벽
// 2 : 바이러스
void Solution(vector<vector<int>> labotary)
{
    // 모든 0을 찾아가면서 벽을 세워본다.
    for (size_t y = 0; y < N; y++)
    {
        for (size_t x = 0; x < M; x++)
        {
            if(labotary[y][x] == 0)
            {
                vector<vector<int>> copyLabotary = labotary;
                copyLabotary[y][x] = 1;  // 벽을 세운다.
                BuildWall(copyLabotary, 1);
                copyLabotary[y][x] = 0;
            }
        }
    }
}

int main()
{
    cin >> N >> M;
    vector<vector<int>> labotary(N, vector<int>(M));

    for (size_t y = 0; y < N; y++)
    {
        for (size_t x = 0; x < M; x++)
        {
            cin >> labotary[y][x];
        }
    }

    Solution(labotary);
    cout << answer << endl;
    return 0;
}