#include<bits/stdc++.h>

int n;
int dp[1000001];

int main(){
	scanf("%d",&n);
	int sum=0;
	while(n!=1){
		if(n%3!=0){
			sum++;
			n-=1;
		}
		
		
	}
	printf("%d\n",sum); 
	
}
