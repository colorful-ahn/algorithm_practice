#include<bits/stdc++.h>

#define MAX 1000+1

using namespace std;

struct Info{
	int x,y;
};
queue<Info> q;

int n,m;
int MAP[MAX][MAX];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
bool visited[MAX][MAX]; 
int count_[MAX][MAX];


// 거리를 숫자로 어떻게 표현할지
// 1 한개를 어떻게 없앨 지. 

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
		if(!visited[xnxt][ynxt] && MAP[xnxt][ynxt]==0){
			count_[xnxt][ynxt] += count_[x][y];
			visited[xnxt][ynxt]=true;
			q.push({xnxt,ynxt});
		}
	}
	}
	
}

int main(){
	
	

	
	for(int i=0;i<MAX;i++){
		for(int j=0; j<MAX; j++){
			MAP[i][j]=1;
			count_[i][j]=1;
		}
	}
	scanf("%d%d",&n,&m);
	char str[m];
	for(int i=0; i<n;i++){
		scanf("%s",&str);
		for(int j=0; j<m;j++){
			MAP[i][j] = str[j]-'0';
		}
	}
	//입력 받고
	q.push({0,0});
	visited[0][0]=true;
	BFS();
	int min=count_[n-1][m-1];
	
	for(int i=0;i<n;i++){
		for(int j=0; j<m; j++){
			if(MAP[i][j]==1){
				MAP[i][j]=0;
				memset(visited,false,sizeof(visited));
				q.push({0,0});
				visited[0][0]=true;
				BFS();
				MAP[i][j]=1;
				if(min>count_[n-1][m-1] && count_[n-1][m-1]!=1){
					min = count_[n-1][m-1];
				}
			}
		}
		
	}
	if(min==1){
		printf("-1");
	}else{
		printf("%d",min);
	}
		
	
}
