#include <iostream>
#include <vector>

using namespace std;

#define max(a, b) a > b ? a : b

// 
vector<vector<long long>> MoveUp(vector<vector<long long>> board)
{
    vector<vector<long long>> result = board;
    int N = result.size();
    vector<vector<bool>> check(N, vector<bool>(N, false));

    // 2번째 행부터 시작한다
    for (int y = 1; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            if (result[y][x] == 0) continue;  // 빈칸이면 건너뛴다.

            for (int i = y - 1; i >= 0; --i)
            {
                // 같으면 합친다!
                if (result[i][x] == result[i + 1][x] && !check[i][x])
                {
                    result[i][x] *= 2;
                    result[i + 1][x] = 0;
                    check[i][x] = true;
                    break;
                }
                // 빈칸이면 바꾼다.
                else if (result[i][x] == 0)
                {
                    result[i][x] = result[i + 1][x];
                    result[i + 1][x] = 0;
                }
                else
                {
                    break;
                }
            }
        }
    }

    return result;
}

vector<vector<long long>> MoveDown(vector<vector<long long>> board)
{
    vector<vector<long long>> result = board;
    int N = result.size();
    vector<vector<bool>> check(N, vector<bool>(N, false));

    // 마지막 2번째 행부터 시작한다
    for (int y = N - 2; y >= 0; --y)
    {
        for (int x = 0; x < N; ++x)
        {
            if (result[y][x] == 0) continue;  // 빈칸이면 건너뛴다.

            for (int i = y + 1; i < N; ++i)
            {
                // 같으면 합친다!
                if (result[i][x] == result[i - 1][x] && !check[i][x])
                {
                    result[i][x] *= 2;
                    result[i - 1][x] = 0;
                    check[i][x] = true;
                    break;
                }
                // 빈칸이면 바꾼다.
                else if (result[i][x] == 0)
                {
                    result[i][x] = result[i - 1][x];
                    result[i - 1][x] = 0;
                }
                else
                {
                    break;
                }
            }
        }
    }

    return result;
}

vector<vector<long long>> MoveLeft(vector<vector<long long>> board)
{
    vector<vector<long long>> result = board;
    int N = result.size();
    vector<vector<bool>> check(N, vector<bool>(N, false));

    // 두번째 열부터
    for (int y = 0; y < N; ++y)
    {
        for (int x = 1; x < N; ++x)
        {
            if (result[y][x] == 0) continue;  // 빈칸이면 건너뛴다.

            for (int i = x - 1; i >= 0; --i)
            {
                // 같으면 합친다!
                if (result[y][i] == result[y][i + 1] && !check[y][i])
                {
                    result[y][i] *= 2;
                    result[y][i + 1] = 0;
                    check[y][i] = true;
                    break;
                }
                // 빈칸이면 바꾼다.
                else if (result[y][i] == 0)
                {
                    result[y][i] = result[y][i + 1];
                    result[y][i + 1] = 0;
                }
                else
                {
                    break;
                }
            }
        }
    }

    return result;
}

vector<vector<long long>> MoveRight(vector<vector<long long>> board)
{
    vector<vector<long long>> result = board;
    int N = result.size();
    vector<vector<bool>> check(N, vector<bool>(N, false));

    // 마지막 2번째 열부터 시작한다
    for (int y = 0; y < N; ++y)
    {
        for (int x = N - 2; x >= 0; --x)
        {
            if (result[y][x] == 0) continue;  // 빈칸이면 건너뛴다.

            for (int i = x + 1; i < N; ++i)
            {
                // 같으면 합친다!
                if (result[y][i] == result[y][i - 1] && !check[y][i])
                {
                    result[y][i] *= 2;
                    result[y][i - 1] = 0;
                    check[y][i] = true;
                    break;
                }
                // 빈칸이면 바꾼다.
                else if (result[i][x] == 0)
                {
                    result[y][i] = result[y][i - 1];
                    result[y][i - 1] = 0;
                }
                else
                {
                    break;
                }
            }
        }
    }

    return result;
}

long long GetMax(vector<vector<long long>> board)
{
    long long maxVal = 0;

    for (auto b : board)
        for (auto n : b)
            maxVal = max(maxVal, n);

    return maxVal;
}

void Solution(vector<vector<long long>> board, int cnt, long long& answer)
{
    // 최대값 갱신
    answer = max(answer, GetMax(board));

    // 최대 움직임이 지났다면
    if (cnt == 5)
        return;

    Solution(MoveUp(board), cnt + 1, answer);
    Solution(MoveDown(board), cnt + 1, answer);
    Solution(MoveLeft(board), cnt + 1, answer);
    Solution(MoveRight(board), cnt + 1, answer);
}

int main()
{
    int N;
    cin >> N;

    vector<vector<long long>> board(N, vector<long long>(N, 0));

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < N; ++x)
        {
            cin >> board[y][x];
        }
    }
    long long answer = -1;
    Solution(board, 0, answer);

    cout << answer << endl;

    return 0;
}