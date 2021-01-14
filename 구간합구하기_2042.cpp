#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> v;
int S;
vector<long> tree;


long makeTree(int node, int left, int right);
long query(int node, int left, int right, int qLeft, int qRight);
void update(int node, int left, int right, int index, long diff);

int main(){
	
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int M,K,x;
	
	S=1;
	
	cin >> N; //수의 개수
	cin >> M; // 변경횟수 
	cin >> K; //구간합 구하는 횟수 
	int result;
	
	while(S<N){
		S*=2;
	}
	tree.assign(S,0);
	v.assign(S,0);
	
	
	for(int i=1; i<=N; i++){
		cin >> x;
		v[i]=x;
	}
	for(int i=1; i<=N; i++){
		cout << v[i];
	}
	
	
	makeTree(1,1,S);
	int a,b,c;
	
	for(int i=0; i<M+K-1;i++){
		cin >> a >> b >> c;
		if(a==1){
			update(1,1,S,b,c);
		}
		else if(a==2){
			result=query(1,1,S,b,c);
		}
	}
	cout << result;
	

	
}

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

long query(int node, int left, int right, int qLeft, int qRight){
	if(qRight<left || right <qLeft){	// out of query
		return 0;
	}else if(qLeft<= left && right <=qRight){	// all in query
		return tree[node];
	}else{				// 일부분만 걸침. 
		int mid = (left + right)/2;
		return query(node*2, left, mid, qLeft, qRight) + query(node*2+1,mid+1,right,qLeft,qRight);
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
