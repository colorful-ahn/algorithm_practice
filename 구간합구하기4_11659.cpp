#include <bits/stdc++.h>

using namespace std; 

int n,m;
int arr[100001];
int sub[100001];

int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n;i++){
		scanf("%d",&arr[i]);
	}
	
	
	int sum;
	
	for(int i=1; i<=n;i++){
		sub[i] = sub[i-1] + arr[i];
	}
	
	for(int i=1; i<=m; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",sub[y]-sub[x-1]);
	}
	
}

