#include<bits/stdc++.h>

#define MAX 502
using namespace std;

int t;
int n,m;
int yet[MAX];
int v[MAX][MAX];
int indegree[MAX];

int main(){
	scanf("%d",&t);
	while(t-->0){
		
		memset(v,0,sizeof(v));
		memset(indegree,0,sizeof(indegree));
		bool flag=false;
		
		scanf("%d",&n);
		for(int i=1; i<=n; i++){
			scanf("%d",&yet[i]);
		}
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				v[yet[i]][yet[j]]=1;
				indegree[yet[j]]++;
			}
		}
		
		scanf("%d",&m);
		for(int i=0; i<m; i++){
			int a,b;
			scanf("%d%d",&a,&b);
			if(v[a][b]){
				v[a][b]=0;
				v[b][a]=1;
				indegree[b]--;
				indegree[a]++;
			}else{
				v[a][b]=1;
				v[b][a]=0;
				indegree[a]--;
				indegree[b]++;
			}
		}
		queue<int> q;
		vector<int> ans;
		for(int i=1;i<=n;i++){
			if(indegree[i]==0){
				q.push(i);
			}
		}
		while(!q.empty()){
			
			if(q.size()>1){
				flag=true;
				break;
			}
			int cur=q.front();
			q.pop();
			ans.push_back(cur);
			for(int i=1;i<=n; i++){
				if(v[cur][i]){
					indegree[i]--;
					if(indegree[i]==0){
						q.push(i);
					}		
				}
			}
		}	
		
		
		if(flag==true){
			printf("?\n");
		}else if(ans.size()==n){
			for(int i=0; i<n; i++){
				printf("%d ",ans[i]);
			}
			printf("\n");
		}else{
			printf("IMPOSSIBLE\n");
		}
		
	}
}
