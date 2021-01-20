#include <bits/stdc++.h>
#define MAX 100+1

using namespace std; 

struct Info{
	int x,y;
};



queue<Info> q;
int MAP[MAX][MAX];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool visited[MAX][MAX];
int count_[MAX][MAX];
int n,m;


void BFS(){
	
	while(!q.empty()){
		int x = q.front().x;
		int y = q.front().y;
		
		q.pop();
		for(int i=0;i<4;i++){
		int xnxt,ynxt;
		xnxt = x + dx[i];	// 좌우이동 
		ynxt = y + dy[i];	// 상하이동
		if(xnxt > n-1 || ynxt >m-1 || xnxt <0 || ynxt <0) continue;
		if(!visited[xnxt][ynxt] && MAP[xnxt][ynxt]==1){
			count_[xnxt][ynxt] += count_[x][y];
			visited[xnxt][ynxt]=true;
			q.push({xnxt,ynxt});
		}
	}
	}
	
}
int main(){
	
	memset(visited,false,sizeof(visited));
	
	scanf("%d%d",&n,&m);
	char str[m];
	for(int i=0;i<n;i++){
		scanf("%s",&str);
		for(int j=0;j<m;j++){
			MAP[i][j] = str[j]-'0';
			count_[i][j] = 1;
		}
	}
	q.push({0,0});
	BFS();

//	for(int i=0;i<n;i++){
//		for(int j=0;j<m;j++){
//			printf("%d ",count_[i][j]);
//		}
//		printf("\n");
//	}
	printf("%d",count_[n-1][m-1]);
}
