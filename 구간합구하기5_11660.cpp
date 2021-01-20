#include <bits/stdc++.h>


int n,m;
int arr[1025][1025];
int sum[1025][1025];	//[i][j] : 1행 1열부터 i행j열까지의 합 

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		for(int j=1; j<=n; j++){
			scanf("%d",&arr[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		int line =0;
		for(int j=1; j<=n; j++){
			line +=arr[i][j];
			sum[i][j] = sum[i-1][j] + line;
		}
	}
	int ans =0 ;
	for(int i=0; i<m; i++){
		int x1,x2,y1,y2;
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		
		ans = sum[x2][y2] - sum[x2][y1-1] - sum[x1-1][y2] + sum[x1-1][y1-1];
		printf("%d\n",ans);
	}
	
}
