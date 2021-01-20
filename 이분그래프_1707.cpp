#include <bits/stdc++.h>
#define MAX 20000+1

using namespace std;

int k,v,e;
vector<int> v[MAX];

void DFS(int v){
	visited[v]=1;
	for(int i=0; i<=n; i++){
		if(map_[v][i] && !visited[i]){
			DFS(i);
		}
	}
}


int main(){
	scanf("%d",&k);
	for(int i=0;i<k;i++){
		scanf("%d%d",&v,&e);
		for(int j=0; j<e;j++){
			int x,y;
			scanf("%d%d",&x,&y);
			v[x].push_back(y);
			v[y].push_back(x);
		}
	}
} 
