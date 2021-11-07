#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

typedef long long int ll;

ll N, K;
map<ll, ll> dic;
vector<pair<ll, ll>> v;
int cnt = 0;

ll gcd(ll a, ll b) {
    if (b == 0) {
        return a;
    }
    gcd(b, a % b);
}

void solve() {
    for (auto it : dic) {
        v.push_back(it);
    }

    for (int i = 0; i < v.size(); i++) {
        if (v[i].first *
            v[i].first *
            v[i].first % K == 0
            && v[i].second >= 3) {
            cnt += (v[i].second - 2) * (v[i].second - 1) * (v[i].second) / 6;
        }
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            if (v[i].first * v[i].first * v[j].first % K == 0
                && v[i].second >= 2) {
                cnt += (v[i].second - 1) * (v[i].second) * (v[j].second) / 2;
            }

            if (v[j].first * v[j].first * v[i].first % K == 0 && v[j].second >= 2) {
                cnt += (v[j].second - 1) * (v[j].second) * (v[i].second) / 2;
            }
        }
    }

    for (int i = 0; i < v.size(); i++) {
        for (int j = i + 1; j < v.size(); j++) {
            for (int k = j + 1; k < v.size(); k++) {
                if (v[i].first * v[j].first * v[k].first % K == 0) {
                    cnt += v[i].second * v[j].second * v[k].second;
                }
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> N >> K;

    for (int i = 0; i < N; ++i)
    {
        ll tmp;
        cin >> tmp;

        ll k = gcd(tmp, K);

        if (dic.find(k) == dic.end()) dic[k] = 0;
        dic[k]++;
    }

    solve();

    cout << cnt << endl;

    return 0;
}