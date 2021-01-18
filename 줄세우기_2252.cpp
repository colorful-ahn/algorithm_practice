#include<bits/stdc++.h>

#define MAX 32000+1


using namespace std;

int N,M;
int indegree[MAX];
vector <int> v[MAX];
queue <int> q;

int main(){
	
	scanf("%d %d",&N,&M);
	
	for(int i=0; i<M; i++){
		int a,b;
		scanf("%d %d",&a,&b);
		
		v[a].push_back(b);
		indegree[b]++;
		
		
		
	}
	// indegree가 0 인것을 찾는다.
	for(int i=1; i<=N; i++){
		if(indegree[i]==0){
			q.push(i);
			
		}
	} 
	
	while(!q.empty()){
		int cur = q.front();
		q.pop();
		printf("%d ",cur);
		for(int i=0; i<v[cur].size(); i++){
			int next = v[cur][i];
			indegree[next]--;
			if(indegree[next] == 0){
				q.push(next);
			}
		}
	}
	
}  
