#include <iostream>
#include <vector>

using namespace std;

int N, M;

int v[9];
bool visited[9];

void dfs(int cnt) {
    if(cnt == M) {
        for (int i = 0; i < M; i++)
        {
            /* code */
            cout << v[i] << " ";
        }
        cout << "\n";
        return;        
    }

    for(int i = 1; i <= N; ++i) {
        if(visited[i] == false) {
            visited[i] = true;
            v[cnt] = i;
            dfs(cnt + 1);
            // 이거 없으면 백 트래킹 안 함
            visited[i] = false;
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> M ;
    dfs(0);
    return 0;
}