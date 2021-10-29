#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main (){
    int N, M;
    N = 3;
    M = 1;

	// 1부터 6까지 담을 벡터
	vector<int> n;

	// 1부터 6까지 생성
	for(int i=0; i<N; i++){
		n.push_back(i+1);
	}

	// 0과1을 저장 할 벡터 생성
	vector<int> ind;

	// k개의 1 추가
	for(int i=0; i<M; i++){
		ind.push_back(1);
	}

	// 2개(6개-2개)의 0 추가
	for(int i=0; i<n.size()-M; i++){
		ind.push_back(0);
	}

	// 정렬
	sort(ind.begin(), ind.end());

	//순열
	do{
		// 출력
		for(int i=0; i<ind.size(); i++){
			if(ind[i] == 1){
				printf("%d ", n[i]);
			}
		}

		printf("\n");

	}while(next_permutation(ind.begin(), ind.end()));

	return 0;

}