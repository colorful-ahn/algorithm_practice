#include<bits/stdc++.h>

#define MAX 101

using namespace std; 

queue<int> q;
int map_[MAX][MAX];
int visited[MAX]; 
int N,M;

void BFS(int v){
	// 디큐, 체크인
	int count=0;
	q.push(v);
	visited[v] =1;
	// 도달했는가?
	while(!q.empty()){
		v = q.front();
		q.pop();
		
		
		
		for(int i=1; i<=N; i++){
		if(map_[v][i]==1 && !visited[i]){
			q.push(i);
			visited[i]=1;
			count+=1;
		}
		}	
	}
	
	
	//가능한 곳 순회
	
	//도달
	
	//인큐
	printf("%d",count);
	 
} 

int main(){
	
	memset(map_,0,sizeof(map_));
	memset(visited,0,sizeof(visited));
	
	scanf("%d %d",&N,&M);
	
	for(int i=0; i<M;i++){
		int a,b;
		scanf("%d %d",&a,&b);
		map_[a][b] =1;
		map_[b][a] =1;
		
	}
	
	BFS(1);
	
	
	
} 
