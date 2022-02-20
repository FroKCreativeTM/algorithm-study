// 출처 : https://programmers.co.kr/learn/courses/30/lessons/64065
// 풀은 사람 : 차승철(FroK)
// 풀은 날짜 : 2022-02-20

#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <sstream>

#define pp pair<int,int>

using namespace std;

bool cmp(const pp& a, const pp& b) {
	if (a.second == b.second) return a.first < b.first;
	return a.second > b.second;
}

vector<string> split(string input, char delimiter) {
    vector<string> answer;
    stringstream ss(input);
    string temp;
 
    while (getline(ss, temp, delimiter)) {
        answer.push_back(temp);
    }
 
    return answer;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    s.erase(std::remove(s.begin(), s.end(), '{'), s.end());
    s.erase(std::remove(s.begin(), s.end(), '}'), s.end());
    
    vector<string> numList = split(s, ',');
    
    map<int, int> m;
    for(auto n : numList)
    {
        m[stoi(n)]++;
    }
    
	vector<pp> vec( m.begin(), m.end() );
	sort(vec.begin(), vec.end(), cmp);
    
	for (auto num : vec) {
        answer.push_back(num.first);
    }
    
    return answer;
}