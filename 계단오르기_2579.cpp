#include <bits/stdc++.h>


int n;
int arr[301],point1[301],point2[301];

int getmax(int a,int b){
	return a>b? a:b;
}

int main(){
	scanf("%d",&n);
	
	for(int i=1; i<=n;i++){
		scanf("%d",&arr[i]);
	}
	
	
	point1[1] = arr[1];
	
	for(int i=0; i<=n; i++){
		point1[i] = getmax(point1[i-2],point2[i-2]) + arr[i];
		point2[i] = point1[i-1] + arr[i];
	}
	
	printf("%d",getmax(point1[n],point2[n]));
}
