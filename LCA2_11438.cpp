#include<bits/stdc++.h>

#define MAX 100000+1
using namespace std;

int N,M, depth[MAX], an[MAX][18];  // 2^0, 2^1, 2^2.....
vector <int> v[MAX];
bool visited[MAX];

void DFS(int parent,int cur ,ink d){
	if (visited[cur]) return;
	else{
		visited[cur]=true;
		depth[cur] = d;
		ans[cur][0] = parent;
		for(int i; i<v[cur].size();i++){
			DFS(cur,v[cur][i],d+1);
		}
	}
}

int LCA(int a, int b){
	if(depth[a]<depth[b]){
		int tmp = a;
		a = b;
		b = tmp;
		
	} // ���� ���̰� ���� �ٸ��� �����ش�
	if(depth[a]!=depth[b]){
		// a-->b ���� ���̸� �����.
		int diff = depth[a] - depth[b];
		
		for(int i=0; i<=17; i++){
			//if(diff & (1<<i)
			int j=2;
			if(diff & j) {
				a = an[a][i];
			}
			j*=2;
		}
	}
		// depth[a] == depth[b] �� ����
		if(a == b) return 0;
		
		for(int i=17; i>=0; i--){
			if(an[a][i]!=an[b][i]){
				a = an[a][i];
				b = an[b][i];
			}
		} 
		return a[][]
	
}


int main(){
	
	
	scanf("%d",&N);    // ����� ����
	
	for(int i=1; i<N; i++){
		int a,b;
		// node ����
		
		scanf("%d %d",&a,&b);
		 v[a].push_back(b);
		 v[b].push_back(a);
		 
	} 
	//to LCA  1/2/3/.....parent
	
	DFS(1,1,1);
	
	for(int i=1; i<=17;i++){
		for(int j=1; j<=N; j++){		//1�����~ n����� 
			int tmp = an[j][i-1];
			an[j][i] = an[tmp][i-1];
		}
	}
	scanf("%d",&M);
	for(int i=0; i<M; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		printf("%d\n",LCA(a,b));
	}
	
}
