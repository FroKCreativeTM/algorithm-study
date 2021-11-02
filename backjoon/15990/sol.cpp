#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
	int T, dp[100001][4], a;
    
    // 메모이제이션
	for(int i=1; i<=100000; i++){
		if(i==1){
			dp[i][1] = 1;
			dp[i][2] = 0;
			dp[i][3] = 0;
		}
		else if(i==2){
			dp[i][1] = 0;
			dp[i][2] = 1;
			dp[i][3] = 0;
		}
		else if(i==3){
			dp[i][1] = 1;
			dp[i][2] = 1;
			dp[i][3] = 1;
		}
		else{
			dp[i][1] = (dp[i-1][2] + dp[i-1][3])%1000000009;
			dp[i][2] = (dp[i-2][1] + dp[i-2][3])%1000000009;
			dp[i][3] = (dp[i-3][1] + dp[i-3][2])%1000000009;
		}
	}
    
    cin >> T;

	for(int i=0; i<T; i++){
		cin >> a;
		printf("%d\n", ((dp[a][1]+dp[a][2])%1000000009+dp[a][3])%1000000009);
	}
}