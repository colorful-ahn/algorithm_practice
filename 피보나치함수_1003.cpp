#include<bits/stdc++.h>

int t,n;
int dp[41];

int fibo(int n){
	if(n==0){
		dp[0]=1;
		return 0;
	}else if(n==1){
		dp[1]=1;
		return 1;
	}
	if(dp[n]!=0){
		return dp[n];
	}else{
		dp[n] = fibo(n-1) + fibo(n-2);
		return dp[n];
	}
}

int main(){
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		memset(dp,0,sizeof(dp));
		scanf("%d",&n);
		fibo(n);
		if(n==0){
			printf("%d %d\n",1,0);
		}
		else if(n==1){
			printf("%d %d\n",0,1);
		}else{
			printf("%d %d\n",dp[n-1],dp[n]);
		}
	}
}
