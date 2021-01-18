#include<bits/stdc++.h>

#define MAX 501


using namespace std;

int N,M,ans=0,cnt,rcnt;
int indegree[MAX];
vector <int> v[MAX];
vector <int> vr[MAX];

bool visited[MAX];
bool Rvisited[MAX];

void DFS(int cur){
	if(visited[cur]){
		return;  
	}else{
		visited[cur]=true;
		cnt++;
		for(int i=0; i<v[cur].size(); i++){
			DFS(v[cur][i]);
		}
	}
}
void RDFS(int cur){
	if(Rvisited[cur]){
		return;  
	}else{
		Rvisited[cur]=true;
		rcnt++;
		for(int i=0; i<vr[cur].size(); i++){
			RDFS(vr[cur][i]);
		}
	}
}


int main(){
	
	scanf("%d %d",&N,&M);
	
	
	for(int i=0; i<M; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		// a �� b ���� ����. 
		v[a].push_back(b);
		vr[b].push_back(a);
	}
	// ������ ū ���� ��
	// ������ ���� ���� ��
	// ��� �� ������ �Ǿ����� Ȯ���غ�
	 
	 // ������ ū ���
	for(int i=1; i<=N; i++){
		cnt = 0;
		memset(visited,0,sizeof(visited));
		DFS(i);
		rcnt = 0;
		memset(Rvisited,0,sizeof(Rvisited));
		RDFS(i);
		if(cnt+rcnt-1 == N){
			ans+=1;
		}
	}
	printf("%d",ans); 	
} 
