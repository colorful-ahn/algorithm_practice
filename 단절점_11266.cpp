#include<bits/stdc++.h>
#define MAX 10000+1

using namespace std;


int V,E,cnt,num=1;
int visit[MAX];
bool ans[MAX];
vector<int> adj[MAX];

// 예외 : 루트일 경우
// 나의 방문 순서보다 자식들의 방문순서가 자신보다 작은 경우 

int getmin(int p, int q){
	if(p<q) return p;
	else return q;
}


int DFS(int parent, int cur, bool isRoot){
	int min_visit = 20000; 	// 내 자식들이 만날 수 있는 점 중에서 가장 작은 점 
	int chlcnt = 0;
	visit[cur] = num;		// 나(=cur)의 번호 
	num++;
	
	for (int i=0; i<adj[cur].size(); i++){
		int nxt = adj[cur][i];
		if( nxt == parent) continue;	
			if(visit[nxt]){
				min_visit = getmin(visit[nxt],min_visit);
			}
		 else{		//새롭게 방문하는 경우 
			int tmp = DFS(cur,nxt,false);
			min_visit = getmin(tmp,min_visit);
			if(isRoot !=true && tmp >=visit[cur]){
				ans[cur] = true;
			}
			chlcnt++;
		}
	}
	if(adj[cur].size()==1){
		return visit[cur];
	}
	if(isRoot){
		// 자식이 두개인지 체크해서 두개 이상이면 단절 점 
		if(chlcnt>=2){
			ans[cur] = true;
	
		}
	}
	return getmin(min_visit,visit[cur]);	//내가 만난 점 중에서 방문 순서가 가장 낮은 점 
}



int main(){
	memset(ans,false,sizeof(ans));
	memset(visit,0,sizeof(visit));
	scanf("%d %d",&V,&E);
	
	for(int i=0; i<E;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		adj[a].push_back(a);
		adj[b].push_back(b);
	}
	// 단절점 찰고 출력
	for(int i=1; i<=V;i++){
		if(visit[i] == 0){			//그래프가 모두 연결되어있는 상태가 아니기 때문 
			DFS(0,i,true);			// 시작하는 점을 root로 정한다. 
		}
	}	
	for(int i=1; i<=V; i++){
		if(ans[i]){
			cnt++;
		}
	}
	printf("%d\n",cnt);
	for(int i =1; i<=V;i++){
		if(ans[i]){
			printf("%d ",i);
		}
	} 
	
}
