#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> people(N, -1);

    for (size_t i = 0; i < N; i++)
    {
        cin >> people[i];
    }
    
    sort(people.begin(), people.end());

    int answer = 0;
    int last = 0;

    for(auto time : people) {
        last += time;
        answer += last;
    }
    
    cout << answer << endl;

    return 0;
}