#include <bits/stdc++.h>
 
int N,M;
int pr[201];


int findf(int a){
	if(pr[a]==a) return a;
	pr[a] = findf(pr[a]);
	return pr[a];
}

void merge(int a, int b){
	int a1,b1
	a1 = findf(a);
	b1 = findf(b);
	if(a1==b1) return;
	pr[b]=a;
}

int main(){
	scanf("%d",&N);
	scanf("%d",&M);
	pr[0] = 0;
	for(int i=1; i<=N;i++){
		pr[i]=i;
	}
	for(int i =1; i<=N;i++){
		for(int j=1; j<=N; j++){
			int x;
			scanf("%d",&x);
			if(x==1){
				if(findf(i)!=findf(j)){
					merge(i,j);	
				}
			}	
		}
	}	
	int k;
	bool flag = true;
	scanf("%d",&k);
	k=findf(k);
	
	for(int i=1; i<M; i++){
		int x;
		scanf("%d",&x);
		if(k!=findf(x)){
			flag=false;
			break;
		}
	}
	if(flag==false){
		printf("NO");
	}else{
			printf("YES");
	}

	return 0;
}
