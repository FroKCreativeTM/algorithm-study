#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int X[4] = {1, 0, -1, 0};
int Y[4] = {0, 1, 0, -1};

string map[26];
vector<int> vec;
int cnt = 0;
int n;

void dfs(int y, int x) {
		if(x < 0 || x>= n || y < 1 || y>= n + 1 || map[y][x] != '1') return;

		map[y][x] = '0';
        cnt++;
        
        for(int i = 0; i < 4; ++i) {
            dfs(y + Y[i], x + X[i]);
        }
}

void solve() {
    for(int y = 1; y <= n; ++y) {
        for(int x = 0; x < n; ++x) {
            if(map[y][x] == '1') {
                dfs(y, x);
                vec.push_back(cnt);
                cnt = 0;
            }
        }
    }
}

int main() {
    cin >> n;

    for (int y = 1; y <= n; ++y)
    {
        string t;
        cin >> t;
        map[y] = t;
    }
    
    solve();
    sort(vec.begin(), vec.end());

    cout << vec.size() << endl;
    for(auto i : vec) {
        cout << i << endl;
    }
}