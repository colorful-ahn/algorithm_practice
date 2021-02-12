#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n,m,k;
ll fen[1000001]={0,};
ll total[1000001]={0,};

int main(){
	scanf("%d%",&n);
	for(int i=1; i<=n; i++){
		ll x;
		scanf("%lld",&x);
		fen[i] = x;
	}
	scanf("%d%",&m);
	for(int i=0; i<m; i++){
		int x;
		scanf("%d",&x);
		if(x==1){
			int a,b;
			ll val;
			scanf("%d%d%lld",&a,&b,&val);
			for(int j=a; j<=b; j++){
				if(val==0) continue;
				total[j]+=val;
			}
		}
		else if(x==2){
			int a;
			scanf("%d",&a);
			if(total[a]==0){
					printf("%lld\n",fen[a]);
			}else{
				fen[a] += total[a];
				total[a]=0;
				printf("%lld\n",fen[a]);
			}
			
			
		}
	}
}
