#include<bits/stdc++.h>
int arr[1001][1001] = {0};

int main(){
	
	int N,K;
	
	scanf("%d %d", &N, &K);
	
	
	
	for(int i=1; i<=N; i++){
		for(int j=0; j<=K;j++){
			if(i==j || j==0){
				arr[i][j] = 1;
				continue;
			}
			arr[i][j] = (arr[i-1][j]+arr[i-1][j-1])%10007;
		}
	}
	
	
	printf("%d", arr[N][K]);
	
	
	return 0;
}
