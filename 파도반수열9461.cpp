#include<bits/stdc++.h>

long long dp[101];
int t,n;


long long tri(int n){
	if(n==1 || n==2 || n==3) return dp[n]=1;
	if(n==4 || n==5) return dp[n]=2;
	if(dp[n]!=0) return dp[n];
	dp[n] = tri(n-5) + tri(n-1);
	return dp[n];
}



int main(){
	scanf("%d",&t);
	for(int i=0;i<t;i++){
		scanf("%d",&n);
		printf("%lld\n",tri(n));
	}
	
}
