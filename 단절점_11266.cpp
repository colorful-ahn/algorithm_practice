#include<bits/stdc++.h>
#define MAX 10000+1

using namespace std;


int V,E,cnt,num=1;
int visit[MAX];
bool ans[MAX];
vector<int> adj[MAX];

// ���� : ��Ʈ�� ���
// ���� �湮 �������� �ڽĵ��� �湮������ �ڽź��� ���� ��� 

int getmin(int p, int q){
	if(p<q) return p;
	else return q;
}


int DFS(int parent, int cur, bool isRoot){
	int min_visit = 20000; 	// �� �ڽĵ��� ���� �� �ִ� �� �߿��� ���� ���� �� 
	int chlcnt = 0;
	visit[cur] = num;		// ��(=cur)�� ��ȣ 
	num++;
	
	for (int i=0; i<adj[cur].size(); i++){
		int nxt = adj[cur][i];
		if( nxt == parent) continue;	
			if(visit[nxt]){
				min_visit = getmin(visit[nxt],min_visit);
			}
		 else{		//���Ӱ� �湮�ϴ� ��� 
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
		// �ڽ��� �ΰ����� üũ�ؼ� �ΰ� �̻��̸� ���� �� 
		if(chlcnt>=2){
			ans[cur] = true;
	
		}
	}
	return getmin(min_visit,visit[cur]);	//���� ���� �� �߿��� �湮 ������ ���� ���� �� 
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
	// ������ ���� ���
	for(int i=1; i<=V;i++){
		if(visit[i] == 0){			//�׷����� ��� ����Ǿ��ִ� ���°� �ƴϱ� ���� 
			DFS(0,i,true);			// �����ϴ� ���� root�� ���Ѵ�. 
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
