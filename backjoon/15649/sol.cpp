#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<vector<int>> answer;

int main() {
	ios::sync_with_stdio(false);
    cin.tie(nullptr);

    /* 조합문제~~~~~~~ */
    int N, M;

    cin >> N >> M;

    vector<int> v;
    for(int i = 1; i <= N; ++i) {
        v.push_back(i);
    }

    vector<bool> cb;
    int tmp = 0;
    for(int i = 0; i < v.size(); ++i) {
        if(tmp < v.size() - M) {
            cb.push_back(false);
            tmp++;
        } else {
            cb.push_back(true);
        }
    }

    do {
        vector<int> tmp;
		for (int i = 0; i < cb.size(); i++) {
		    if (cb[i])  {
                tmp.push_back(v[i]);
            }
		}
        answer.push_back(tmp);
    } while(next_permutation(cb.begin(), cb.end()));

    for(int i = answer.size() - 1; i >= 0; --i) {
        for(int j = answer[i].size() - 1; j >= 0;  --j) {
            cout << answer[i][j] << " ";
        }
        cout << endl;
    }
}