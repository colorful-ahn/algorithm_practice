#include<bits/stdc++.h>

#define MAX 20000+1
#define INF 300000

using namespace std; 

struct Info{
	int b,c;
	Info(int bb, int cc){
		b=bb;
		c=cc;
	}
};

struct Dijk_Info{
	int node_num, node_dist;
	Dijk_Info(int nn, int nd){
		node_num = nn;
		node_dist = nd;
	}
};

struct comp{
	bool operator()(Dijk_Info a, Dijk_Info b){
		return a.node_dist > b.node_dist;
	}
};

int V,e, dist[MAX],start;
vector<Info> v[MAX];


void dijk(){
	priority_queue<Dijk_Info, vector<Dijk_Info>,comp> pq;
	// start distance setting + pq input
	dist[start]=0;
	pq.push(Dijk_Info(start,0));
	while(!pq.empty()){
		Dijk_Info cur = pq.top();
		pq.pop();
		if(cur.node_dist > dist[cur.node_num]) continue;
		
		
		// cur의 주변을 탐색
		for(int i=0; i< v[cur.node_num].size();i++){
			Info nxt = v[cur.node_num][i];
			int tmp = cur.node_dist + nxt.c;	// 현재 점(cur)에서 다음 점(nxt)로 이동할 때 드는 비용 
			if(tmp  < dist[nxt.b]){
				dist[nxt.b] = tmp;
				pq.push(Dijk_Info(nxt.b,tmp));
			}
			
		} 
	}
}


int main(){
	scanf("%d %d",&V,&e);
	scanf("%d",&start);
	
	for(int i=0; i<e; i++){
		int a,b,c;
		scanf("%d %d %d",&a,&b,&c);
		v[a].push_back(Info(b,c)); 	// a --> b weight == c;
 		
	}
	for(int i=1; i<=V; i++){
		dist[i] = INF;
	}
	// dijkstra
	dijk();
	
	// print
	for(int i=1; i<=V; i++){
		if(dist[i] == INF){
			printf("INF\n");
		}else{
			printf("%d\n",dist[i]);
		}		
	}
} 
