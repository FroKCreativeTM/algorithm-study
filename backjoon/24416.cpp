#include <iostream>

using namespace std;

int cnt1 = 0;
int cnt2 = 0;

int fibo1(int n) {
    if(n == 1 || n == 2) {
        return 1;
    } else {
        cnt1++;
        return fibo1(n - 1) + fibo1(n - 2);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n;
    cin >> n;
    
    fibo1(n);
    
    cout << cnt1  + 1<< " " << n - 2 << endl;
    
    return 0;
}