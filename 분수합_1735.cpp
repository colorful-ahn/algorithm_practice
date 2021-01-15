#include<bits/stdc++.h>

using namespace std;


int GCD(int a, int b){
		while(b>0){
			long long r;
			r= a%b;
			a = b;
			b = r;
		}
	return a;
}


int main(){
	int A1,B1,A2,B2;
	int gcd;
	scanf("%d %d",&A1,&B1); 
	scanf("%d %d",&A2,&B2); 
	
	int C1,C2;
	
	gcd = GCD(B1,B2);
	
	C2 = B1*B2/gcd;
	C1 = C2/B1*A1 + C2/B2*A2;
	
	gcd = GCD(C2,C1);
	
	
	
	
	printf("%d %d",C1/gcd,C2/gcd);
 
}
