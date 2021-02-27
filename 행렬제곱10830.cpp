#include<bits/stdc++.h>
typedef long long ll;
int n;
ll b;
ll hang[6][6];
ll result[6][6];

void h(ll x[6][6] ,ll y[6][6]){
	ll temp[6][6]={0,};
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			for(int k=0; k<n; k++){
				temp[i][j] +=x[i][k]*y[k][j];
			}
			temp[i][j]%=1000;
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			x[i][j]=temp[i][j];
		}
	}
}

void divide(ll count){ 
	while(count>1){
		if(count%2==1){
				for(int i=0; i<n; i++){
					for(int j=0; j<n; j++){
						hang[i][j]=result[i][j];
					}
				}
			}
		count/=2;
		h(result,result);
	}
	
	
}

int main(){
	scanf("%d%lld",&n,&b);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			scanf("%d",&result[i][j]);
			
		}
		hang[i][i]=1;
	}
	divide(b);
	h(result,hang);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			printf("%lld  ",result[i][j]);
		}
		printf("\n");
	}
}
