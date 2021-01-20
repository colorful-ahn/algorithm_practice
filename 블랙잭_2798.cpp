#include <bits/stdc++.h>


int n,m;
int arr[101];
int arr1[101];
int getmax(int a,int b){
	return a>b? a:b;
}

int main(){
	scanf("%d%d",&n,&m);
	int max =0; 
	for(int i=0; i<n;i++){
		scanf("%d",&arr[i]);
	}
	int sum=0;
	int ans=0;
	for(int i=0; i<n; i++){
		for(int j=i+1; j<n; j++){
			for(int k=j+1; k<n; k++){
				sum= arr[i]+arr[j]+arr[k];
				if(m>=sum){
					ans=getmax(sum,ans);
				}	
			}
		}
	}
	printf("%d",ans);
	
}
