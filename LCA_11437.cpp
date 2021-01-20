#include<bits/stdc++.h>
#define MAX 50000+1

using namespace std;

int n,m;
vector<int> v[MAX];
vector<int> p;
vector<int> d;
bool visited[MAX];

void dep(int cur,int parent){
	visited[cur] = true;					
	d[cur] += d[parent]+1;
	for(int i=0; i<v[cur].size(); i++){
		int nxt = v[cur][i];
		if(!visited[nxt] && v[cur][i]!=0){
			p[nxt] = cur;
			dep(nxt,cur);
		}
	}	
}


int solution(int a, int b){
	if(a==b) return a;
	int x,y,pa,pb;
	x=d[a];
	y=d[b];
	pa = p[a];
	pb = p[b];
	if(pa==pb) return pa;
	if(pa==b) return b;
	if(pb==a) return a;
	if(x!=y){
		if(x>y){
			return solution(pa,b);
		}else{
			return solution(a,pb);
		}
	}
	return solution(pa,pb);	
} 


int main(){
	scanf("%d",&n);
	d.assign(n,0);
	p.assign(n,0);
	for(int i=0; i<n-1; i++){
		int a,b;
		scanf("%d %d",&a,&b);

		v[a].push_back(b);
		v[b].push_back(a);		// Â÷ÀÏµå  	
	}
	p[1]=1;
	dep(1,0);
	
	scanf("%d",&m);
	int arr[m];
	for(int i=0; i<m; i++){
		memset(visited,false,sizeof(visited));
		int a, b;
		scanf("%d %d",&a,&b);
		arr[i] = solution(a,b);
	}

	for(int i=0; i<m;i++){
		printf("%d\n",arr[i]);
	}
	
}
