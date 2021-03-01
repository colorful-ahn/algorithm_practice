#include<bits/stdc++.h>

#define MAX 101
using namespace std;

int n;
char pic[MAX][MAX];
bool visited[MAX][MAX];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
queue<pair <int,int> > q;


void BFS(){
	while(!q.empty()){
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for(int i=0; i<4; i++){
			int xnxt = x+dx[i];
			int ynxt = y+dy[i];
			if(xnxt<0||xnxt>n||ynxt<0||ynxt>n) continue;
			if(!visited[xnxt][ynxt] && pic[x][y]==pic[xnxt][ynxt]){
				visited[xnxt][ynxt] = true;
				q.push(make_pair(xnxt,ynxt));
			}
		}
	}
}

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> pic[i][j];
		}
	}
	int normal=0,rok=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!visited[i][j]){
				normal++;
				visited[i][j]=true;
				q.push(make_pair(i,j));
				BFS();
				
			}
		}
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(pic[i][j]=='G') pic[i][j]='R';
		}
	}
	memset(visited,false,sizeof(visited));
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(!visited[i][j]){
				rok++;
				visited[i][j]=true;
				q.push(make_pair(i,j));
				BFS();
			}
		}
	}
	printf("%d %d",normal,rok);
	
}
