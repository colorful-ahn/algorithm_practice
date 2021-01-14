#include <bits/stdc++.h>

using namespace std;

vector<long long> tree;
vector<long long> v;


void makeTree(long long N, long long S){
	for(long long i=0; i<N; i++){
		tree[S+i] = v[i+1];
	}
	for(long long i= S-1; i>0; i--){
		tree[i] = tree[i*2] + tree[i*2+1];
	}
}

long long query(long long left,long long right,long long S){
	long long result=0;
	left +=S-1;
	right +=S-1;
	while(left<=right){
		if (left%2==1){
			result += tree[left++];
		}
		if(right%2==0){
			result+=tree[right--];
		}
		left/=2;
		right/=2;
	}
	return result;
}

void update(int index, int value,long long S){
	index +=S-1;
	tree[index]=value;
	index/=2;
	while(index>=1){
		tree[index] = tree[index*2] + tree[index*2+1];
		index/=2;
	}
}

int main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	long long S,N;
	int Q;
	int n;
	int x,y,a,b;
	long long result;
	
	cin >> N >> Q;

	S=1;
	while(S<N){
		S*=2;
	}
	
	tree.assign(4*S+1,0);
	v.assign(2*N,0);
	
	
	for(int i=1; i<=N; i++){
		cin >> n;
		v[i]=n;
	}
	makeTree(N,S); 
	for(int i=0; i<Q;i++){
		cin >> x >> y>> a>> b;
		if(x<=y){
			result = query(x,y,S);
			update(a,b,S);
		cout << result << "\n";
		}else{
			result = query(y,x,S);
			update(a,b,S);
			cout << result << "\n";
		}
		
	}
}
