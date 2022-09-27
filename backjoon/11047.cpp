#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int answer = 0;

    int N, total;
    cin >> N >> total;

    vector<int> coin(N, -1);

    for (size_t i = 0; i < N; i++)
    {
        cin >> coin[i];
    }

    for(int i = coin.size() - 1; i >= 0; --i) {
        int tmp = total / coin[i];

        if(tmp > 0) {
            answer += tmp;
            total -= (coin[i] * tmp);
        }
    }

    cout << answer << endl;
    
    return 0;
}