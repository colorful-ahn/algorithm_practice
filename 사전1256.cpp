#include<bits/stdc++.h>


using namespace std;

int arr[101][101];
int dp[101][101];
vector<char> str;




int combination(int n, int r){
	// r ==0, n== r
	// D[n][r] = D[n-1]+D[n-1][r]
	
	
	if( n==r || r==0 ){
		return 1;
	}else if(dp[n][r]!=0){
		return dp[n][r];
	}
	else{
		return dp[n][r] = min(combination(n-1,r-1) + combination(n-1,r),1000000000);
	}
	return 0;
}


void query(int n, int m, int k){
	// n== 0 m ==0
	// n == 0 
	if(n + m ==0){
		return;
	}else{
	
	if(n==0){
		str.push_back('z');
		query(n,m-1,k);
	}else if(m==0){
		str.push_back('a');
		query(n-1,m,k);
	}else{
		int leftCount = combination(n+m-1,m);
		if(leftCount >=k){
			str.push_back('a');
			query(n-1,m,k);
		}else{
			str.push_back('z');
			query(n,m-1,k-leftCount);
		}
	}
	// m == 0
	// n+m-1 C m  => 분기
	}
}




int main(){
	
	//1. 파스칼 삼각형 그리기.
	//2. 경계 정리
	int N,M,K;
	
	scanf("%d %d %d", &N, &M,&K);
	
	if(K>combination(N+M,M)){
		printf("-1\n");
	}else{
		query(N,M,K);
		for(int i=0; i<N+M;i++){
		printf("%c",str[i]);
	}	
	}
	
	
	
	
	
}
