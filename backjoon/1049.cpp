#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    // 끊어진 기타줄 수 : N
    // 기타줄 브랜드 M
    int N, M;

    cin >> N >> M;
    vector<int> package(M, -1);
    vector<int> individually(M, -1);
    for (size_t i = 0; i < M; i++)
    {
        // 패키지의 가격과 낱개의 가격
        cin >> package[i] >> individually[i];
    }

    // 1. 패키지로만!
    // 2. 낱개로만
    // 3. 패키지 + 낱개!

    sort(package.begin(), package.end());
    sort(individually.begin(), individually.end());

    int cnt1 = 0;
    cnt1 += (N / 6) * package[0];
    if(N % 6 != 0) cnt1 += package[0];

    int cnt2 = 0;
    cnt2 += individually[0] * N;

    int cnt3 = 0;
    int tmp = N / 6; 
    if(N < 6) {
       cnt3 += 1 * package[0];
    } else {
       cnt3 += (N / 6) * package[0];
    }
    tmp = N % 6;
    cnt3 += individually[0] * tmp;

    int answer = min(cnt1, cnt2);
    answer = min(answer, cnt3);

    cout << answer << endl;

    return 0;
}