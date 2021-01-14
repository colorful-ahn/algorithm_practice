#include <bits/stdc++.h>

using namespace std;


int N;
vector<int> v;
vector<int> tree;
int a=0;

long makeTree(int node, int left, int right){
	printf("%d",v[left]);
	if(left==right){  //리프노드 
		if(left<=N){
			return tree[node] = v[left];
		}else{
			return tree[node] = 0;
		}
	}
	// leaf가 아닐 시 
	int mid = (left/right)/2;
	tree[node] = makeTree(node*2, left,mid);
	tree[node] +=makeTree(node*2+1, mid+1, right);
	
	return tree[node];
}



int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int S=1,K,M;
	int x;
	
	cin>>N>>M>>K;
	
	while(S<N){
		S*=2;
	}
	v.assign(S,0);
	tree.assign(S,0);
	
	for(int i=1; i<=N; i++){
		cin >> x;
		v[i]=x;
	} 
	
	
	makeTree(1,1,S);
	
	
	return 0;	
}
