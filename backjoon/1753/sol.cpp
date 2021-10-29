#include <iostream>
#include <vector>
#include <queue>

using namespace std;

const int MAX_INF = 10000;
const int MAX_VEC_SIZE = 20001;

int V, E;   // 정점, 간선 갯수
int K;      // 사직 정점
vector<pair<int, int>> vec[MAX_VEC_SIZE];
int mc[MAX_VEC_SIZE];                                      // min cost

void dijkstra(int start) {
    priority_queue<pair<int, int>> pq;

    pq.push(make_pair(start, 0));
    mc[start] = 0;

    // 가까운 순서대로
    while(!pq.empty()) {
        int cur = pq.top().first;

        // 짧은 것은 먼저오게 음수화
        int dist = -pq.top().second;
        pq.pop();

        if(mc[cur] < dist) continue;

        for(int i = 0; i < vec[cur].size(); ++i) {
            // 선택된 노드의 인접 노드
            int next = vec[cur][i].first;
            int nextDist = dist + vec[cur][i].second;

            if(nextDist < mc[next]) {
                mc[next] = nextDist;
                pq.push(make_pair(next, -nextDist));
            }
        }
    }

    for(int i = 1; i <= V; ++i) {
        if(mc[i] == MAX_INF) {
            cout << "INF\n";
        } else {
            cout << mc[i] << '\n';
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> V >> E;
    cin >> K;

    for(int i = 1; i <= E; ++i) {
        int u, v, w;
        cin >> u >> v >> w;
        vec[u].push_back(make_pair(v, w));
    }

    for(int i = 1; i <= V; ++i) {
        mc[i] = MAX_INF;
    }

    dijkstra(K);    

    return 0;
}