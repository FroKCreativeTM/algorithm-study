#include <iostream>
#include <vector>

using namespace std;

long long fib[50] = {0, 1,};
int cnt[2];

int fibonacci(int n) {
    if(n == 0 || n == 1) {
        return fib[n];
    } else if(fib[n] == 0) {
        fib[n] = fibonacci(n - 1) + fibonacci(n - 2); 
    } 
    return fib[n];
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;

    cin >> n;

    // 아예 메모이제이션
    fibonacci(40);

    for(int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        if(tmp == 0)
            // 시간을 아끼자.
            cout << "1 0" << '\n';
        else
            cout << fib[tmp - 1] << ' ' <<  fib[tmp] << '\n';
    }
}