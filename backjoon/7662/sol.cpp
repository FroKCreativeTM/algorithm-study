#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

multiset<int> answer;

void Solution(vector<pair<char, int>> dq)
{
    answer.clear();

    for (auto p : dq)
    {
        if(p.first == 'I')
        {
            answer.insert(p.second);
        }
        if(p.first == 'D')
        {
            if (answer.empty()) continue;

            if(p.second == -1)
            {
                answer.erase(answer.begin());
            }
            else if(p.second == 1)
            {
                auto iter = answer.end();
                iter--;
                answer.erase(iter);
            }
        }
    }
    
}

int main()
{
    int N;
    cin >> N;

    for(int i = 0; i < N; ++i)
    {
        int size;
        cin >> size;
        vector<pair<char, int>> elem(size);

        for (size_t i = 0; i < size; i++)
        {
            char c;
            int n;

            cin >> c >> n;
            elem[i].first = c;
            elem[i].second = n;
        }

        Solution(elem);
        // 정답 출력

        if(answer.empty())
        {
            cout << "EMPTY" << endl;
        }
        else
        {
            auto iter = answer.end();
            iter--;
            cout << *iter << " " << *answer.begin() << endl;
        }
    }

    return 0;
}