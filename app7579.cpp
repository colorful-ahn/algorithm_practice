#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

int n,m;
ll arr[10001]={0,};
ll byte[101]={0,};
int cost[101]={0,};
int sum=0;

ll get_max(ll a, ll b){
	return a>b? a:b;
}


int main(){
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; i++){
		int x;
		scanf("%d",&x);
		byte[i]=x;
	}
	for(int i=1; i<=n; i++){
		int x;
		scanf("%d",&x);
		cost[i]=x;
		sum+=cost[i];
	}

	for(int i=0; i<n;i++){
		for(int j=sum; j>=cost[i];j--){
			arr[j]=get_max(arr[j],arr[j-cost[i]]+byte[i]);
			}
		}
	int i=0;	
	for(i=0; i<sum,arr[i]<m; i++);
	printf("%d",i);
	
}
