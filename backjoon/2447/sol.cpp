#include <iostream>

using namespace std;

void DrawStar(int y, int x, int n)
{
    if((y / n) % 3 == 1 && (x / n) % 3 == 1) 
    {
        cout << " ";
    }
    else
    {
        if(n / 3 == 0) 
            cout << "*";
        else
            DrawStar(y, x, n / 3);
    }
}

void Solution(int N)
{
    for (size_t y = 0; y < N; ++y)
    {
        for (size_t x = 0; x < N; ++x)
        {
            DrawStar(y, x, N);
        }
        cout << endl;
    }
}

int main()
{
    int N;
    cin >> N;

    Solution(N);

    return 0;
}