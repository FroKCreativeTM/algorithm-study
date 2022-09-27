#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int>& cards, int result)
{
    int answer = -1;

    for (size_t i = 0; i < cards.size() - 2; i++)
    {
        for (size_t j = i + 1; j < cards.size() - 1; j++)
        {
            for (size_t k = j + 1; k < cards.size(); k++)
            {
                if(result < cards[i] + cards[j] + cards[k])
                    break;
                answer = max(answer, cards[i] + cards[j] + cards[k]);
            }
        }
    }

    return answer;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<int> v;
    for (size_t i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        v.push_back(num);
    }
    sort(v.begin() ,v.end());

    cout << solution(v, M) << endl;

    return 0;
}