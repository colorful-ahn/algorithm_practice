#include<bits/stdc++.h>



int main(){
	
	int N;
	scanf("%d",&N);
	
	int x=0,y=0;
	
	if(N<5){
		if(N==3){
			printf("1");
		}else{
			printf("-1");
		}
	}else{
		for(int i=0; i<N; i++){
			
			if(5*i<=N){
				if((N-5*i)%3==0){
					x=(N-5*i)/3;
					y=i;
				}
			}
			
		}
	if(x==0&&y==0){
		printf("-1");
	}else{
		printf("%d",x+y);	
	}	
}
}
