#include <bits/stdc++.h>

int n,tri[501][501] ,ans[501][501],res=0;



int getmax(int a,int b){
	return a>b? a:b;
}


int main(){
	memset(tri,0,sizeof(tri));
	memset(ans,0,sizeof(ans)); 
	
	scanf("%d",&n);
	for(int i=1; i<=n;i++){
		for(int j=1; j<=i; j++){
			scanf("%d",&tri[i][j]);
		}
	}
	ans[1][1] = tri[1][1];
	
	for(int i=2; i<=n; i++){
		for(int j=1; j<=i; j++){
			ans[i][j] = getmax(ans[i-1][j],ans[i-1][j-1]) + tri[i][j];
			
		}
	}
	for(int i=1; i<=n; i++){
		res = getmax(ans[n][i],res);
	}
	printf("%d",res);
}
