#include<bits/stdc++.h>
int n;
long long fac(int n){
	if(n>0){
		return n*fac(n-1);	
	}
	return 1;		
}
int main(){
	scanf("%d",&n);
	printf("%lld",fac(n));
} 
