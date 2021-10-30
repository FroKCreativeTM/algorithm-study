#include <iostream>
#include <queue>

using namespace std;

int map[101][101];
int visited[101];
int cnt;
queue<int> q;
int n,m;

void solve(int start) {
    visited[start] = 1;
    q.push(start);

    while(!q.empty()) {
        int node = q.front();
        q.pop();

        for(int i = 1; i <= n; ++i) {
            if(map[node][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                cnt++;
                q.push(i);
            }
        }    
    }
}

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> n >> m;

    for(int i = 0; i < m; ++i) {
        int start, end;
        cin >> start >> end;
        map[start][end] = map[end][start] = 1;
    }

    solve(1);

    cout << cnt << "\n";
}
