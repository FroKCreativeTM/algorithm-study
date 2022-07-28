#include <iostream>
#include <vector>
#include <numeric>
#include <climits>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, window_size;
    vector<int> nums;

    cin >> N >> window_size;

    for (size_t i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        nums.push_back(num);
    }
    
    // 누적합?
    int cnt = 0;
    int sum = 0;
    int answer = INT_MIN;
    for(int i = 0; i < N; ++i) {
        sum += nums[i];

        if(i >= window_size - 1) {
            answer = max(sum, answer);
            sum -= nums[cnt++];
        }
    }

    cout << answer << endl;

    return 0;
}