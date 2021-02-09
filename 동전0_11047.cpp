#include<bits/stdc++.h>

int n,k;
int arr[11];
int count=0;

int main(){
	scanf("%d%d",&n,&k);
	for(int i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	for(int i=n-1; i>=0; i--){
		if(arr[i]<=k){
			while(1){
				k -= arr[i];
				count++;
				if(arr[i]>k) break;
			}
		}
	}

	printf("%d",count);
}
