#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dx[6] = {1, -1, 0, 0, 0, 0};
int dy[6] = {0, 0, 1, -1, 0, 0};
int dz[6] = {0, 0, 0, 0, 1, -1};

struct Pos
{
    int _z, _y, _x;
    Pos() : _z(-1), _y(-1), _x(-1) {}
    Pos(int z, int y, int x) : _z(z), _y(y), _x(x) {}
};

bool IsInside(int z, int y, int x, int maxZ, int maxY, int maxX)
{
    return (z >= 0) && (z < maxZ) &&(y >= 0) && (y < maxY) && (x >= 0) && (x < maxX);
}

int solution(vector<vector<vector<int>>>& storage)
{
    int answer = -1;

    const int maxZ = storage.size();
    const int maxY = storage[0].size();
    const int maxX = storage[0][0].size();

    queue<Pos> q;
    // 맨 아래 맨 오른쪽부터 시작한다.
    
    for (size_t z = 0; z < maxZ; z++)
    {
        for (size_t y = 0; y < maxY; y++)
        {
            for (size_t x = 0; x < maxX; x++)
            {
                if(storage[z][y][x] == 1)
                    q.push(Pos(z, y, x));
            }
        }
    }

    while(!q.empty())
    {
        int z = q.front()._z;
        int y = q.front()._y;
        int x = q.front()._x;
        q.pop();

        for (size_t i = 0; i < 6; i++)
        {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];

            if(IsInside(nz, ny, nx, maxZ, maxY, maxX) && storage[nz][ny][nx] == 0)
            {
                storage[nz][ny][nx] = storage[z][y][x] + 1;
                q.push(Pos(nz, ny, nx));
            }
        }
    }

    for (size_t z = 0; z < maxZ; z++)
    {
        for (size_t y = 0; y < maxY; y++)
        {
            for (size_t x = 0; x < maxX; x++)
            {  
                if(storage[z][y][x] == 0)
                    return -1;

                answer = max(storage[z][y][x], answer);
            }
        }
    }

    return answer - 1;
}

int main()
{
    int N, M, H;

    cin >> N >> M >> H;
    vector<vector<vector<int>>> v(H, vector<vector<int>>(M, vector<int>(N, -1)));
    for (size_t z = 0; z < H; z++)
    {
        for (size_t y = 0; y < M; y++)
        {
            for (size_t x = 0; x < N; x++)
            {
                cin >> v[z][y][x];
            }
        }
    }

    cout << solution(v) << endl;

    return 0;    
}