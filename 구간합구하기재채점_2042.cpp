#include<bits/stdc++.h>

#define ll long long 

using namespace std;

int n,m,k;

ll fen[1000001];

void update(int at, ll by) {
    for(;at<=n;at+=at&-at) fen[at]+=by;
}
ll query(int at) {
    if(at==0) return 0;
 
    ll ret=0;
    for(;at>0;at-=at&-at) ret+=fen[at];
    return ret;
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1; i<=n; i++){
		ll x;
		scanf("%lld",&x);
		update(i,x);
	}
	for(int i=0; i<m+k;i++){
		int x;
		scanf("%d",&x);
		if(x==1){
			ll a,b;
			scanf("%lld%lld",&a,&b);
			int idx = query(a)-query(a-1);
			update(a,b-idx);
		}else if(x==2){
			ll a,b;
			scanf("%lld%lld",&a,&b);
			printf("%lld\n",query(b)-query(a-1));
		}
	}
}
