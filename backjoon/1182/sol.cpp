#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

int N, S, K;
int* arr;
int* choice;
int cnt = 0;

void comb(int n, int idx, int m) {
    if(idx > m) {
        // 작업하고 나간다.
        if(S == accumulate(choice + 1, choice + m + 1, 0)) {
            cnt++;
        }
        return;
    }

    // 집합의 원소의 갯수를 넘어가면 샐피
     if(n > N) {
         return;
     }

    // 선택한 원소를 선택 배열에 저장한다.
    choice[idx] = arr[n];

    // 1. 선택 후 다음
    // 2. 미선택 후 다음
    comb(n + 1, idx + 1, m);
    comb(n + 1, idx, m);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> S;
    arr = new int[N + 1];
    choice = new int[N + 1];

    for(int i = 1; i <= N; ++i) {
        cin >> arr[i];
    }   

    // 부분 집합 갯수를 늘려간다.
    for(int i = 1; i <= N; ++i) {
        comb(1, 1, i);
    }   
    
    cout << cnt << endl;
    return 0;
}