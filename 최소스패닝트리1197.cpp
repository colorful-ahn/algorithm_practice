#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 10001

using namespace std;

int n,m;

int pr[MAX];
int ans=0;

class Edge{
    public:
    int node[2];
    int d;
    Edge(int a, int b, int d){
        this->node[0]=a;
        this->node[1]=b;
        this->d=d;
    }
    bool operator <(Edge &edge){
        return this->d < edge.d;
    }
};

vector<Edge> v;

int findf(int a){
    if(pr[a]==a) return a;
    pr[a]=findf(pr[a]);
    return pr[a];
}

int check(int a,int b){
   return findf(a)==findf(b)? 1:0;
}

void unionf(int a, int b){
    a = findf(a);
    b = findf(b);
    if(a>b) pr[a]=b;
    else pr[b]=a;
}

int main(){
    scanf("%d%d",&n,&m);
	for(int i=0; i<m; i++){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		v.push_back(Edge(a,b,c));
	} 
    
    sort(v.begin(),v.end());

    for(int i=1;i<=n;i++){
        pr[i]=i;
    }
    for(int i=0; i<v.size();i++){
        int flag=check(v[i].node[0],v[i].node[1]);
        if(!flag){
            ans+=v[i].d;
            unionf(v[i].node[0],v[i].node[1]);
        }
    }

    printf("%d",ans);



}
