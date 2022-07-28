#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

struct Pos
{
    int _y, _x;
    Pos() : _y(-1), _x(-1) {}
    Pos(int y, int x) : _y(y), _x(x) {}
};

bool IsInside(int y, int x, int maxY, int maxX)
{
    return (y >= 0) && (y < maxY) && (x >= 0) && (x <= maxX);
}

int solution(vector<vector<int>>& storage)
{
    int answer = -1;

    const int maxY = storage.size();
    const int maxX = storage[0].size();

    queue<Pos> q;
    // 맨 아래 맨 오른쪽부터 시작한다.
    
    for (size_t y = 0; y < maxY; y++)
    {
        for (size_t x = 0; x < maxX; x++)
        {
            if(storage[y][x] == 1)
                q.push(Pos(y, x));
        }
    }

    while(!q.empty())
    {
        int y = q.front()._y;
        int x = q.front()._x;
        q.pop();

        for (size_t i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(IsInside(ny, nx, maxY, maxX) && storage[ny][nx] == 0)
            {
                storage[ny][nx] = storage[y][x] + 1;
                q.push(Pos(ny, nx));
            }
        }
    }

    for (size_t y = 0; y < maxY; y++)
    {
        for (size_t x = 0; x < maxX; x++)
        {  
            if(storage[y][x] == 0)
                return -1;

            answer = max(storage[y][x], answer);
        }
    }

    return answer - 1;
}

int main()
{
    int N, M;

    cin >> N >> M;
    vector<vector<int>> v(M, vector<int>(N, -1));
    for (size_t y = 0; y < M; y++)
    {
        for (size_t x = 0; x < N; x++)
        {
            cin >> v[y][x];
        }
    }

    cout << solution(v) << endl;

    return 0;    
}