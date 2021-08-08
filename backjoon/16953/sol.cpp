#include <iostream>

using namespace std;

int A, B;

int main() {
    cin >> A >> B;
    int answer = 0;

    while(true) {
        if(B < A) {
            cout << -1 << endl;
            return 0;
        }

        if(B == A) {
            cout << answer + 1 << endl;
            break;
        }

        if(B % 10 == 1) {
            B /= 10;
        } else if (B % 2 == 0) {
            B /= 2;
        } else {
            cout << -1 << endl;
            break;
        }
        answer++;
    }

    return 0;
}