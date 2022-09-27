#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int dx[4] = {1, -1, 0, 0};
const int dy[4] = {0, 0, 1, -1};

vector<int> answer;

bool IsInside(int y, int x, int maxN) 
{
    return (y >= 0) && (y < maxN) && (x >= 0) && (x < maxN);
}

void dfs(vector<vector<int>> island, int y, int x, int height) 
{
    // 밖이거나 해수면보다 낮은 경우
    if(!IsInside(y, x, island.size()) || island[y][x] < height) {
        return;
    }

    island[y][x] -= height;

    for (size_t i = 0; i < 4; i++)
    {
        dfs(island, y + dy[i], x + dx[i], height);
    }
}

void solution(vector<vector<int>>& island)
{
    int result = 0;
    int n = island.size();

    int minHeight = 100'000'000 , maxHeight = -1;

    for (size_t y = 0; y < n; y++)
    {
        for (size_t x = 0; x < n; x++)
        {
            minHeight = min(minHeight, island[y][x]);
            maxHeight = max(maxHeight, island[y][x]);
        }
    }

    vector<vector<int>> tmp = island;
    for (size_t h = minHeight; h <= maxHeight; h++)
    {
        int t = 0;
        for (size_t y = 0; y < n; y++)
        {
            for (size_t x = 0; x < n; x++)
            {
                if(island[y][x] > h) {
                    dfs(island, y, x, h);
                    t++;
                }
            }
            result = max(result, t);
            // 원복
            island = tmp;
        }
    }

    answer.push_back(result);
}

int main()
{
    int c;
    cin >> c;

    for (int i = 0; i < c; i++)
    {
        int n;
        cin >> n;

        vector<vector<int>> v(n, vector<int>(n, -1));

        for (size_t y = 0; y < n; y++)
        {
            for (size_t x = 0; x < n; x++)
            {
                cin >> v[y][x];
            }
        }

        solution(v);
    }

    for (size_t i = 0; i < answer.size(); i++)
    {
        cout << "#" << i + 1 << " " << answer[i] << " ";
    }
    cout << endl;
    

    return 0;
}