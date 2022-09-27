#include <iostream>
#include <vector>

using namespace std;

void SwapStuffs(vector<vector<int>>& Stuffs,
    int idx1, int idx2)
{
    int tmp = Stuffs[idx1][0];
    Stuffs[idx1][0] = Stuffs[idx2][0];
    Stuffs[idx2][0] = tmp;

    tmp = Stuffs[idx1][1];
    Stuffs[idx1][1] = Stuffs[idx2][1];
    Stuffs[idx2][1] = tmp;
}

int Solution(vector<vector<int>> Stuffs,
                int K)
{
    int answer = 0;
    vector<vector<int>> dp(Stuffs.size() + 1, vector<int>(K + 1));

    // Build table dp[][] in bottom up manner
    for(int i = 0; i <= Stuffs.size(); i++)
    {
        for(int w = 0; w <= K; w++)
        {
            if (i == 0 || w == 0)
                dp[i][w] = 0;
            else if (Stuffs[i - 1][0] <= w)
                dp[i][w] = max(Stuffs[i - 1][1] +
                                dp[i - 1][w - Stuffs[i - 1][0]],
                                dp[i - 1][w]);
            else
                dp[i][w] = dp[i - 1][w];
        }
    }
    return dp[Stuffs.size()][K];
}

int main()
{
    int N, K;
    cin >> N >> K;
    vector<vector<int>> Stuffs(N, vector<int>(2, -1));

    for (size_t i = 0; i < N; i++)
    {
        int W, V;
        cin >> W >> V;

        Stuffs[i][0] = W;
        Stuffs[i][1] = V;
    }
    
    cout << Solution(Stuffs, K) << endl;

    return 0;
}