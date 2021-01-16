#include <bits/stdc++.h>

#define MAX  25


using namespace std;

int N;
int map_[MAX][MAX];
int visited[MAX][MAX];
int sum;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1}; 

vector<int> ans;


void DFS(int i,int j){
	visited[i][j]=1;
	sum+=1;
	for(int d=0; d<4; d++){
		int nx = i+dx[d];
		int ny = j+dy[d];
		if(nx < 0 || ny <0 || nx >=N || ny >=N){
			continue;
		}
		if(map_[nx][ny]==1 && visited[nx][ny]==0){
			DFS(nx,ny);
		}
	}
}
//	if(map_[i][j+1]==1 && visited[i][j+1]==0){	// 자기 밑에 애들 
//			j+=1;
//			DFS(i,j);
//		}
//	else if(map_[i][j-1] == 1 && visited[i][j-1]==0){
//			j-=1;
//			DFS(i,j);
//	}else if(map_[i+1][j] == 1&& visited[i+1][j]){
//		i+=1;
//		DFS(i,j);
//	}		

int main(){
	
	cin >> N;
	
	
	memset(visited,N,0);
	memset(map_,MAX,0);
	
	for(int i=0; i<N;i++){
		string str;
		for(int j=0; j<N; j++){
			cin >> str[j];
			map_[i][j] = str[j]-'0';
		}
	}
	
	for(int i=0; i<N;i++){
		for(int j=0; j<N;j++){
			if(map_[i][j] == 1 && visited[i][j]==0){
				sum = 0;
				DFS(i,j);
				ans.push_back(sum);		
			}
			
		}
			
	}
	
	sort(ans.begin(),ans.end());
	cout << ans.size() << "\n";
	for(int i=0; i<ans.size();i++){
		cout<<ans[i]<<"\n";
	}
	
	
}
