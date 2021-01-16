#include<bits/stdc++.h>

#define MAX 1001

using namespace std;

int map_[MAX][MAX];
int visited[MAX];
queue<int> q;
int n,m,v;   // n == 정점의 개수  m == 간선의 개수 v는 탐색을 시작할 번호.
 


 

void BFS(int v){
	//큐에서 꺼냄
	visited[v]=1;
	q.push(v);
	// 목적지에 도착?
	while(!q.empty()){
		v = q.front();
		q.pop();
		
		printf("%d ",v);
		for(int i=1; i<=n; i++){
			if(map_[v][i] && !visited[i]){
				q.push(i);
				visited[i] = 1;
			}
		}
	}
	//연결된 곳을 순회 
	//  갈 수 있는가??
	// 체크인& 큐에 넣음 
}

void DFS(int v){
	printf("%d ",v);
	//체크인
	visited[v]=1;
	//목적지에 도착?
	for(int i=0; i<=n; i++){
		if(map_[v][i] && !visited[i]){
			DFS(i);
		}
	}
	//연결된 곳을 순회
	// 갈 수 있는가? 
	// 간다. 
	
	
	//체크아웃 
}






int main(){
	scanf("%d %d %d",&n,&m,&v);
	
	memset(map_,0,sizeof(map_));
	memset(visited,0,sizeof(visited));
	
	for(int i=0; i<m; i++){
		int a,b;  					//간선을 연결, 연결되어있음을 1로 표시해줌
		scanf("%d %d",&a,&b);
		map_[a][b] = 1;
		map_[b][a] = 1; 
	}
	
	DFS(v);
	printf("\n");
	
	memset(visited,0,sizeof(visited));
	BFS(v);
	printf("\n");
	
}
