#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<queue>

#define MAX 1001

using namespace std;


int t,n,w;
int cost[MAX];
int indegree[MAX];
vector<int> v[MAX];
queue<int> q;
int ret[MAX];


void cal(){
	for(int i=1; i<=n; i++){
		if(indegree[i]==0){
			ret[i]=cost[i];
			q.push(i);
		}
	}
    while(!q.empty()){
        int x = q.front();
        q.pop();
        if(indegree[x]<1){
        	for(int i=0; i<v[x].size(); i++){
        		int maxcost=ret[x]+cost[v[x][i]];
        		if(ret[v[x][i]]<maxcost){
        			ret[v[x][i]]=maxcost;
        			q.push(v[x][i]);
				}
				indegree[v[x][i]]--;
			}
		}
    }
}

int main(){
    scanf("%d",&t);
    int k;
    
    while(t-->0){  
        int ans=0;
        scanf("%d%d",&n,&k);
        memset(cost,0,sizeof(cost));
        memset(v,0,sizeof(v));
        memset(indegree,0,sizeof(indegree));
        memset(ret,0,sizeof(ret));


        for(int i=1; i<=n;i++){
            scanf("%d",&cost[i]);
        }
        for(int i=1; i<=k;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[x].push_back(y);
            indegree[y]++;
        }
        scanf("%d",&w);
        cal();
        printf("%d\n",ret[w]); 
          
    }
}
