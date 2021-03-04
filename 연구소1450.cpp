#include<bits/stdc++.h>

using namespace std;


int postec[8][8];
int temp[8][8];
int n,m;
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
int ans=0;




void init(int (*map1)[8], int (*map2)[8]){
	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			map1[i][j]=map2[i][j];
			}
		}
	}

void BFS(){
	int virus[8][8];
	init(virus,temp);
	queue<pair<int, int> > q;
    for (int i = 0; i <n; i++) {
        for (int j = 0; j <m; j++) {
            if (virus[i][j]==2) {
                q.push(make_pair(i, j));
            }
        }
    }
	while(!q.empty()){
		int x=q.front().first;
		int y=q.front().second;
		q.pop();
		
		
		for(int i=0; i<4; i++){
			int xnxt=x+dx[i];
			int ynxt=y+dy[i];
			if(xnxt<0||xnxt>=n||ynxt<0||ynxt>=m) continue;
			if(virus[xnxt][ynxt]==0){	
				virus[xnxt][ynxt] = 2;
				q.push(make_pair(xnxt,ynxt));		
			}
		}
	}
	int ret=0;
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(virus[i][j]==0){
				ret+=1;
			}
		}
	}
	
	
	ans=max(ans,ret);
	
}

void dfs(int cnt){
	
	if(cnt==3){
		BFS();
		return;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++){
			if(temp[i][j]==0){
				temp[i][j]=1;
				dfs(cnt+1);
				temp[i][j]=0;
			}
		}
	}
	
}




int main(){
	scanf("%d%d",&n,&m);
	
	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			scanf("%d",&postec[i][j]);
		}
	}

	
	for(int i=0; i<n;i++){
		for(int j=0; j<m; j++){
			if(postec[i][j]==0){
				init(temp,postec);
				temp[i][j]=1;
				dfs(1);
				temp[i][j]=0;
			}
		}
	}
	printf("%d",ans);
}
