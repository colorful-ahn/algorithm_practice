#include<bits/stdc++.h>

#define MAX 51
using namespace std;

int n,m;
queue<pair <int,int> > q;
int arr[MAX][MAX]={0,};
bool visited[MAX][MAX]={0,};
int dx[8]={0,0,1,-1,1,-1,1,-1};
int dy[8]={1,-1,0,0,1,1,-1,-1};
int result=0;

void init(){
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			arr[i][j]=0;
			visited[i][j]=false;
		}
	}
	while(!q.empty()){
		q.pop();
	}
	result=0;
}

void BFS(){
	result++;
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		visited[x][y]=true;
		q.pop();
		for(int i=0; i<8; i++){
			int xnxt = x+dx[i];
			int ynxt = y+dy[i];
			if(xnxt > n || xnxt <0 || ynxt >m || ynxt<0) continue;
			if(!visited[xnxt][ynxt]&&arr[xnxt][ynxt]==1){
				visited[xnxt][ynxt]=true;
				q.push(make_pair(xnxt,ynxt));
			}
		}
	}
}

int main(){
	while(true){
		scanf("%d%d",&m,&n);
		if(n==0&&m==0) break;
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				scanf("%d",&arr[i][j]);
			}
		}
		for(int i=0; i<n; i++){
			for(int j=0; j<m; j++){
				if(arr[i][j]==1&&!visited[i][j]){
					q.push(make_pair(i,j));
					BFS();
				}
			}
		}
		printf("%d\n",result);
		init();
	}
	return 0;
	
}
