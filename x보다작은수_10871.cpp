#include<bits/stdc++.h>

using namespace std;

int main(){
	
	int N,X;
	int x;
	
	scanf("%d %d",&N,&X);
	
	for(int i=0; i<N; i++){
		scanf("%d",&x);
		if(x/X  == 0 && x!=X){
			printf("%d ",x);
		}
		
	}
}
