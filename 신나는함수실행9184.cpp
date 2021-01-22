#include<bits/stdc++.h>

int dp[110][110][110];

int w(int a, int b, int c){
	
	
	if(a<=0||b<=0||c<=0) {
		dp[0][0][0] = 1;
		return dp[0][0][0]; 
	}
	if(dp[a][b][c]!=0) return dp[a][b][c];
	if(a>20||b>20||c>20){
		dp[20][20][20] = w(20,20,20);
		return dp[20][20][20];
	}
	if(a<b&&b<c){
		dp[a][b][c] = w(a,b,c-1) + w(a,b-1,c-1) - w(a,b-1,c);
		return dp[a][b][c];
			} 
	dp[a][b][c] = w(a-1,b,c) + w(a-1,b-1,c) + w(a-1,b,c-1) - w(a-1,b-1,c-1);
	return dp[a][b][c];
}


int main(){
	int a,b,c;
	
	while(true){
		scanf("%d %d %d",&a,&b,&c);
		if(a==-1&&b==-1&&c==-1){
			break;
		}
		printf("w(%d, %d, %d) = %d\n",a,b,c,w(a,b,c));
	}
}
