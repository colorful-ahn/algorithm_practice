#include <bits/stdc++.h>

using namespace std;

vector<long long> tree;
vector<long long> v;




long makeTree(int node, int left, int right){
	cout << "c";
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

long query(int node, int left, int right, int target){
	if(left==right){	// leaf도달 
		return left;
	}else{ 
		int mid = (left + right)/2;
		if(tree[node*2]>=target){	// 왼쪽의 값이 쿼리를 포함 
			return query(node*2,left,mid,target);
		}else{						//오른쪽의 값이 쿼리를 포 
			return query(node*2+1,mid+1,right,target)
		}
	}
}

void update(int node, int left, int right, int index, long diff){
	if(left <= index && index <=right){
		tree[node] += diff;
		if(left != right){
			int mid = (left+right)/2;
			update(node*2, left, mid, index, diff);
			update(node*+1, mid+1,right,index,diff);
		}
	}
} 

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long S,N;
	long long result;
	int a,b,c=0;
	cin >> N;

	S=1;
	while(S<N){
		S*=2;
	}
	
	tree.assign(4*S+1,0);
	v.assign(2*N,0);
	
	for(int i=0; i<N;i++){
		cin >> a >> b;
		if(a==1){				// a five candy and index b 

		}else{
			cin >> c;			//  input candy index b c>0 in c<0 out
		}
	}
}
