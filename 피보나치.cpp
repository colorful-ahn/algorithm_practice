#include<bits/stdc++.h>

int n;


int fibo(int a){
	if(a==0) return 0;
	if(a==1) return 1;
	if(a==2) return 1;
	return fibo(a-1) + fibo(a-2);
}

int main(){
	scanf("%d",&n);
	printf("%d",fibo(n));
}
