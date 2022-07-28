#include <iostream>
#include <set>

using namespace std;

void solution() {
    int N,M;
    
    cin >> N;
    
    set<int> s;
    for(int i = 0; i < N; ++i) {
        int num;
        cin >> num;
        s.insert(num);
    }
    
    cin >> M;
    for(int i = 0; i < M; ++i) {
        int num;
        cin >> num;
        
        if(s.find(num) != s.end()) {
            cout << '1';
        } else {
            cout << '0';
        }
        
        if(i != M - 1) cout << ' ';
    }
    
}

int main() {
    solution();
}