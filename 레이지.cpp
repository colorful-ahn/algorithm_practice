#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

vector<long long> tree;
vector<long long> lazy;
vector<long long> v;


long long makeTree(int node, int start, int end){
	if(start==end)
		return tree[node] = v[start];
	int mid = (start+end)/2;
	return tree[node] = makeTree(node*2,start,mid) + makeTree(node*2+1,mid+1,end); 
}

void update_lazy(int node, int start, int end){
	if(lazy[node]==0) return;
	tree[node]+=(end - start +1) *lazy[node];
	if(start !=end){
		lazy[node*2] +=lazy[node];
		lazy[node*2+1] +=lazy[node];
	}
	
	lazy[node] = 0;
}

long long query(int node, int start,int end,int left,int right){
	update_lazy(node,start,end);
	if(left>end || right<start) return 0;
	if(left <=start && end <= right) return tree[node];
	
	int mid = (start+end)/2;
	return query(node*2,start,mid,left,right) + query(node*2+1,mid+1,end,left,right);
}

void update(int node, int start,int end,int left,int right, long long val){
	update_lazy(node,start,end);
	if(left>end || right < start) return;
	if(left <= start && end<=right){
		tree[node] += (end - start +1)*val;
		
		if(start!=end){
			lazy[node*2]+=val;
			lazy[node*2+1]+=val;
		}
		return;
	}
	int mid=(start+end)/2;
	update(node*2,start,mid,left,right,val);
	update(node*2+1,mid+1,end,left,right,val);
	
	tree[node] = tree[node*2] + tree[node*2+1];
}



int main(){
	
	long long S,N;
	int M,K;
	int x;
	int a,b,c;
	long long result;
	
	scanf("%d",&N);

	S=1;
	while(S<N){
		S*=2;
	}
	
	tree.assign(4*S+1,0);
	lazy.assign(4*S+1,0);
	v.assign(2*N,0);
	
	for(int i=1; i<=N; i++){
		scanf("%d",&x);
		v[i]=x;
	}
	
	
	makeTree(1,1,S);
	scanf("%d",&M);
	for(int i=0; i<M; i++){
		scanf("%d",&a);
		if(a==1){
			long long d;
			scanf("%d%d%lld",&b,&c,&d);
			update(1,1,S,b,c,d);
			
		}
		if(a==2){
			int y;
			scanf("%d",&y);
			result = query(1,1,S,y,y);
			printf("%lld\n",result);
		}
	}
	return 0;
}
