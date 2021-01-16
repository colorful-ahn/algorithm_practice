#include<bits/stdc++.h>

long long x;
long long arr[91];

void fibo(int n){
	int sum1=0,sum2=0;
	
	 	arr[1]=1;
	 	arr[2]=1;
	 	
		for(int i=3; i<=n; i++){
			arr[i] =arr[i-1]+arr[i-2];
		}
	
}

int main(){	
	int n;
	scanf("%d",&n);
	fibo(n); 
	printf("%lld",arr[n]);	
}
