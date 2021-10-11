#include <iostream>
#include <cstdio>

using namespace std;

int N, M;
char** map;
const int MAX_CNT = 10;
int min = INT_MAX;


// 보드판 판별
int check(){
    bool hasRed = false, hasBlue = false;

    for(int i=0;i<N;i++){
        for(int j=0;j<M;j++){
            if(map[i][j]=='R') hasRed=true;
            else if(map[i][j]=='B') hasBlue=true;
        }
    }
    if(!hasBlue) return -1; // 파란 공이 없을 시 실패
    if(!hasRed) return 1; // 빨간 공이 없을 시 성공
    return 0; // 아무것도 아닌 경우
}

void solve(int cnt, int position) {

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie();

    cin >> N >> M;

    map = new char*[N];
    for (int i = 0; i < N; ++i) {
        map[i] = new char[M];
    }

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            cin >> map[r][c];
        }
    }

    solve(0, 0);
}