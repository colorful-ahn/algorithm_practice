#include<bits/stdc++.h>

#define MAX 500+1


using namespace std;

int N,build[MAX],ans[MAX], maxi[MAX];
int indegree[MAX];
vector <int> v[MAX];
queue <int> q;

int main(){
	
	scanf("%d",&N);
	
	for(int i=1; i<=N; i++){
		int a,b;
		scanf("%d",&build[i]);
		
		while(true){
			int a;
			scanf("%d",&a);
			if(a==-1) break;
			v[a].push_back(i);
			indegree[i]++;
		}
	}
	
	for(int i=1; i<=N; i++){
		if(indegree[i]==0){
			q.push(i);
		}
	} 
	
	
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		// 지금 cur을 처리함.  
		ans[cur] = maxi[cur] + build[cur];
		// 다음 건물을 처리함
		for (int i=0; i<v[cur].size();i++){
			int nxt = v[cur][i];
			indegree[nxt]--;
			if(maxi[nxt]<ans[cur]){
				maxi[nxt] = ans[cur];
			}
			if(indegree[nxt]==0){
				q.push(nxt);
			}
		} 
	}
	
	for(int i=1; i<=N; i++){
		printf("%d\n",ans[i]);
	}
	
} 
