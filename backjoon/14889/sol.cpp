#include <iostream>
#include <climits>
#include <vector>
#include <cmath>

using namespace std;

int N;
vector<vector<int>> vec;
int * visited;
int answer = INT_MAX;

void comb(int cnt, int cur){
    if(cnt == N / 2){
        int a = 0;
        int b = 0;
        // check 
        for(int i = 0; i < N; i++){
            for(int j = i + 1; j < N; j++){
                if(visited[i] && visited[j]){
                    a+= vec[i][j];
                    a+= vec[j][i];
                } else if(!visited[i] && !visited[j]){
                    b+= vec[i][j];
                    b+= vec[j][i];
                }
            }
        }
        answer = min(answer, abs(a-b));
    }
    for(int i = 0; i < N; i++){
        if(visited[i] == false && i > cur){
            visited[i] = true;
            comb(cnt + 1, i);
            visited[i] = false;
        }
    }
 
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N;    
    visited = new int[N];

    for (int y = 0;y < N; y++)
    {
        vector<int> tmp;
        for (int x = 0; x < N; x++)
        {
            int t;
            cin >> t;
            tmp.push_back(t);
        }
        vec.push_back(tmp);        
    }
    comb(0, -1);
    cout << answer << endl;
    return 0;
}