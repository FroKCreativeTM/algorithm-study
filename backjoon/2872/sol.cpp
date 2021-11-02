#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    /*
     *  내가 이해한 방식
     *  정렬된 것은 다시 정렬할 필요가 없음
     *  즉 정렬되지 않은 것들에 대한 처리만 하면 된다.
     *  4 1 3 4 2
     *  이 경우는 먼저 2를  맨 위에 올리고 그 다음에  4를 조회한다. 이 때 4는 움직일 필요가 없으니
     *  패스 그 다음에 3도 마찬가지
     *  근데 1의 경우는 맨 앞으로 옮겨줘야 하니
     *  결국 2번 움직이는 결과를 만들게 된다.
    */

    int N;
    cin >> N;
    vector<int> vec(N);

    for (int i = 0; i < N; ++i)
    {
        cin >> vec[i];
    }
    
    int cnt = N;

    for(int i = N - 1; i >= 0; --i) {
        if(cnt == vec[i]) cnt--;
    }

    cout << cnt;
    return 0;
}