#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>

using namespace std;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int left = 10, right = 12;
    
    for(int n : numbers) {
        if(n % 3 == 1 && n < 10) {
            left = n;
            answer.append("L");
        } else if(n % 3 == 0 && n < 10 && n > 0) {
            right = n;
            answer.append("R");
        } else {
            if(n == 0) {
                n = 11;
            }
            
            int l = abs(left - n);
            int r = abs(right - n);
            
            int ld = (l / 3) + (l % 3);
            int rd = (r / 3) + (r % 3);
            
            if(ld == rd)
            {
                if(hand == "right")
                {
                    answer.append("R");
                    right = n;
                }
                else
                {
                    answer.append("L");
                    left = n;
                }
            }
            else if(ld < rd)
            {
                answer.append("L");
                left = n;
            }
            else
            {
                answer.append("R");
                right = n;
            }
        }
    }
    
    return answer;
}