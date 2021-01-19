#include <bits/stdc++.h>

int n,k;

int f(int a){
	if(a==0) return 1;
	else if(a==1) return 1;
	return a*f(a-1);
}

int main(){
	scanf("%d%d",&n,&k);
	int m=n-k;
	n = f(n); //5!
	k = f(k); 
	m = f(m);
	printf("%d",n/(k*m));
}
