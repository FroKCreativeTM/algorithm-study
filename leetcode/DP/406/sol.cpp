class Solution {
public:
    static bool comp(vector<int> p1, vector<int> p2) {
        if(p1[0] == p2[0]) {
            return p1[1] < p2[1];
        } else {
            return p1[0] < p2[0];
        }
    }
    
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), comp);
        vector<int> init { -1, -1 };
        vector<vector<int>> result(people.size(), init);
        
        auto iter = people.begin();
        while(iter != people.end()) {
            int height = (*iter)[0];
            int cur = (*iter)[1];
            int small = 0;
            
            for(int i = 0; i <= cur + small; ++i) {
                if(result[i][0] != -1 && 
                  result[i][0] < height) 
                    small++;
            }
            
            vector<int> tmp { (*iter)[0], (*iter)[1] };
            result[cur + small] = *iter;
            ++iter;
        }
        
        return result;
    }
};