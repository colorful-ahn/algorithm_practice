#include<bits/stdc++.h>

int n;
int arr[10001];
int dp[10001];

int getmax(int a, int b){
	return a>b?a:b;
}


int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	
	//첫번째꺼 선택
	int count=0;
	for(int i=0; i<n; i++){
		int sum += arr[i];
		if(count==1){
			sum+=arr[i+1];
			count=0;
		}else{
			
			sum+=arr[i];
			count++;
			
			sum+=arr[i+1];
			count=0;
		}
	}
	
	//두번째꺼 선택 
} 
