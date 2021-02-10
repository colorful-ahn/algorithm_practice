#include<bits/stdc++.h>
#define ll long long

using namespace std;

int n,m,k;
ll fen[1000001];
ll total[1000001]={0,};

void add(int at, ll val){
	while(at<=n){
		fen[at]+=val;
		at+=at&-at;
	}
}

ll sum(int at){
	if(at==0) return 0;
	ll result=0;
	while(at>0){
		result +=fen[at];
		at-=at&-at;
	}
	return result;
}

int getmax(int a,int b){
	return a>b? a:b;
}
int getmin(int a,int b){
	return a<b? a:b;
}


int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=n; i++){
		ll x;
		scanf("%lld",&x);
		add(i,x);
	}
	for(int i=0; i<m+k; i++){
		int x;
		scanf("%d",&x);
		if(x==1){
			int a,b;
			ll val;
			scanf("%d%d%lld",&a,&b,&val);
			for(int j=a; j<=b; j++){
				total[j]+=val;
			}
		}
		else if(x==2){
			int a,b;
			for(int j=1; j<=1000001; j++){
				if(total[j]==0) continue;
				printf("%d %d\n",j,total[j]);
			}
			scanf("%d%d",&a,&b);
			for(int j=a; j<=b; j++){
				if(total[j]==0) continue;
				add(j,total[j]);
				total[j]=0;
			}
			printf("%lld\n",sum(b)-sum(a-1));
			
		}
	}
}
