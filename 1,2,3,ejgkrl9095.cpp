#include<bits/stdc++.h>

using namespace std;
int t,n;


int main(){
	scanf("%d",&t);
	while(t-->0){
		int arr[11]={0,};
		arr[1]=1; arr[2]=2; arr[3]=4;
		scanf("%d",&n);
		for(int i=4; i<=n; i++) arr[i] = arr[i-3] + arr[i-2] +arr[i-1];
		printf("%d\n",arr[n]);
	}
}
