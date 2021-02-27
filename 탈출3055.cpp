#include<bits/stdc++.h>

using namespace std;

char mapp[51][51];
bool water_visited[51][51];
bool dochi_visited[51][51];
int dx[4]={1,-1,0,0};
int dy[4]={0,0,1,-1};
queue<pair <int,int> > dq;
queue<pair <int,int> > wq;
int r,c;
bool flag=false;
int answer=0;

void WBFS(){
	while(!wq.empty()){
		int x=wq.front().first;
		int y=wq.front().second;
		water_visited[x][y] = true;
		wq.pop();
		for(int i=0; i<4; i++){
			int xnxt = x+dx[i];
			int ynxt = y+dy[i];
			if(xnxt>r || xnxt < 0 || ynxt > c || ynxt<0) continue;
			if(mapp[xnxt][ynxt]=='X' || mapp[xnxt][ynxt]=='D') continue;
				mapp[xnxt][ynxt]='*';
		}
	}
}

void DBFS(){
	while(!dq.empty()){
		int x=dq.front().first;
		int y=dq.front().second;
		dochi_visited[x][y] = true;
		dq.pop();
		for(int i=0; i<4; i++){
			int xnxt = x+dx[i];
			int ynxt = y+dy[i];
			if(mapp[xnxt][ynxt]=='D'){
				printf("%d",answer+1);
				flag=true;
				return;
			}
			if(xnxt>r || xnxt < 0 || ynxt > c || ynxt<0) continue;
			if(mapp[xnxt][ynxt]!='.') continue;
			mapp[xnxt][ynxt]='S';
		}
	}
}

int main(){
	scanf("%d%d",&r,&c);
	for(int i=0; i<r; i++){
		for(int j=0; j<c; j++){
			cin >> mapp[i][j];
			if(mapp[i][j]=='S'){
				dq.push(make_pair(i,j));
			}
			if(mapp[i][j]=='*'){
				wq.push(make_pair(i,j));
			}
		}
	}	
	
	
	while(true){
		int a=0,b=0;
		if(!dq.empty()) {
			DBFS();
			answer++;
		}
		if(!wq.empty()) WBFS();
		if(flag==true) break;
		for(int i=0; i<r; i++){
			for(int j=0; j<c; j++){
			if(mapp[i][j]=='*'&&!water_visited[i][j]){
				wq.push(make_pair(i,j));
				a=1;
			}
			else if(mapp[i][j]=='S'&&!dochi_visited[i][j]){
				dq.push(make_pair(i,j));
				b=1;
			}
			}
		}
		if(a==0 && b==0){
			printf("KAKTUS");
			break;
		}
		
	}
	
	
}
