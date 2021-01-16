#include<bits/stdc++.h>

// 210000000

using namespace std;


int main(){
	
	int A,B,C;
	int N=1;
	int ABC;
	
	scanf("%d %d %d",&A,&B,&C);
	
	if(C-B<0){
		printf("-1");
	}else if(C-B==0){
		printf("-1");
	}else{
		ABC = A / (C-B);
		while(true){
		if(N>ABC){
			break;
		}else{
			N++;
		}
	}
	printf("%d",N);	
	}	
}
