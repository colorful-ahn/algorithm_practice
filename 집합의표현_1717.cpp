#include<bits/stdc++.h>

int n,m;
int pr[1000010];



int findf(int a){
	if ( a == pr[a] ) return a;
	//return findf(p[a]);
	pr[a] = findf(pr[a]);		// 시간초과 해결하기 위한 방법 
	return pr[a];
}

void unionf(int a, int b){
	a = findf(a);
	b = findf(b);
	pr[a] = b;
}




int main(){
	
		
	
	
	scanf("%d %d",&n,&m);
	//초기화 
	for(int i=0; i<=n;i++){
		pr[i]=i;
	}
	while (m-->0){
		int cmd, a,b;
		scanf("%d %d %d",&cmd,&a,&b);
		//cmd == 0 union
		//cmd == 1 find
		if(cmd ==0){
			//union
			 unionf(a,b);
		}else if(cmd ==1){
			//find, print y or n
			if(findf(a) == findf(b)){
				printf("yes\n");
			}else{
				printf("no\n");
			}
		}
	}

	
}
