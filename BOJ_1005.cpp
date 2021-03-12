#include<iostream>
#include<stdio.h>
#include<vector>
#include<cstring>
#include<queue>

#define MAX 1001

using namespace std;


int t;
int cost[MAX];
int order[MAX][MAX];
vector<int> v[MAX];
queue<int> q;
int ret=0;


int get_max(int a, int b){
    return a>b? a:b;
}

void cal(){
    while(!q.empty()){
        int x = q.front();
        q.pop();
        ret+=cost[x];
        int maxcost=-1,maxidx=-1;
        for(int i=0; i<v[x].size(); i++){
            if(cost[v[x][i]]>=maxcost){
                maxcost=cost[v[x][i]];
                maxidx=v[x][i];
            }
        }
        if(maxidx==-1) break;
        //ret+=maxcost;
        q.push(maxidx);
    }
}

int main(){
    scanf("%d",&t);
    int n,k,w;
    
    while(t-->0){  
        int ans=0;
        scanf("%d%d",&n,&k);
        memset(cost,0,sizeof(cost));
        memset(v,0,sizeof(v));


        for(int i=1; i<=n;i++){
            scanf("%d",&cost[i]);
        }
        for(int i=1; i<=k;i++){
            int x,y;
            scanf("%d%d",&x,&y);
            v[y].push_back(x);
        }
        scanf("%d",&w);
        q.push(w);
        cal();
        printf("%d\n",ret);
        ret=0; 
          
    }
}
