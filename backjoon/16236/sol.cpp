#include <iostream>
#include <vector>

using namespace std;

int dy[4] = {-1, 1, 0, 0};
int dx[4] = {0, 0, -1, 1};

void FindFish()
{

}

int Solution(vector<vector<int>> map, int sharkY, int sharkX)
{
    int answer = 0;
    int curSharkSize = 2;   // 처음 상어 크기는 2다.



    return answer;
}

int main()
{
    int n;
    cin >> n;

    vector<vector<int>> map(n, vector<int>(n, -1));
    int sharkY, sharkX;

    for (size_t y = 0; y < n; y++)
    {
        for (size_t x = 0; x < n; x++)
        {
            cin >> map[y][x];
            if(map[y][x] == 9)
            {
                sharkY = y;
                sharkX = x;
            }
        }
    }
    
    cout << Solution(map, sharkY, sharkX) << endl;
    return 0;
}