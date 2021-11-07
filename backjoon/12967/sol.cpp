#include <iostream>
#include <vector>

using namespace std;

/* 현재 문제, 오버플로우 */
long long N, K;
vector<long long> vec;
int cnt = 0;

void solve() {
    for(int p = 0; p < vec.size() - 2; ++p) {
        for(int q = 1; q < vec.size() - 1; ++q) {
            for(int r = 2; r < vec.size(); ++r) {
                if(p == q || q == r || r == p) {
                    continue;
                }

                if((vec[p] * vec[q] * vec[r]) % K == 0) {
                    cnt++;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;
    
    for (int i = 0; i < N; ++i)
    {
        long long tmp;
        cin >> tmp;
        vec.push_back(tmp);
    }
    
    solve();

    cout << cnt << endl;
}