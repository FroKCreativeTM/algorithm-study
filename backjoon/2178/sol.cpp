#include <iostream>
#include <vector>
#include <string>
#include <climits>

using namespace std;

int N, M;
int answer = INT_MAX;
int cnt = 0;

int moveX[4] = {-1,0,1,0};
int moveY[4] = {0,-1,0,1};

void solve(vector<string> vec, int y, int x) {
    if((y + 1) == N  && (x + 1) == M) {
        answer = min(answer, cnt + 1);
        return;
    }

    if(x < 0 || y < 0 || y >= N || x >= M) {
        return;
    }

    if(vec[y][x] == '0') {
        return;
    } else if(vec[y][x] == '1') {
        ++cnt;
    }
    
    for(int i = 0; i < 4; ++i) {
        solve(vec, y + moveY[i], x + moveX[i]);
    }
}

int main() {
    cin >> N >> M;

    vector<string> vec(N);
    for(int i = 0; i < N; ++i) {
        string tmp;
        cin >> tmp;

        vec.push_back(tmp);
    }

    solve(vec, 0, 0);

    cout << answer << endl;

    return 0;
}