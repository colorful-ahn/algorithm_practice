#include <bits/stdc++.h>
int dp[1000001];

int getmin(int a,int b) {
	return a<b?a:b;
}

int main()
{
	dp[1] = 0;
	int n;
	scanf("%d",&n);
	
	for(int i=2; i<=n;i++){
		dp[i] = dp[i-1] + 1;
		if(i%2==0){
			dp[i] = getmin(dp[i/2]+1,dp[i]);
		}
		if(i%3==0){
			dp[i] = getmin(dp[i/3]+1,dp[i]);
		}
	}

	printf("%d",dp[n]);
}
