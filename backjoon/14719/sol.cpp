#include <iostream>
#include <vector>
using namespace std;

void solve() {
    
}

int main() {
    int H, W;
    cin >> H >> W;
    int* arr = new int[W];
    
    for (int i = 0; i < W; ++i) {
        int n = 0;
        cin >> n;
        
        if(n > H) {
            return 0;
        }
        
        arr[i] = n;
    }

    // v를 순회한다.
    
    for(int i = 0; i < W; ++i) {
        
    }
    
}