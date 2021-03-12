#include<iostream>
#include<algorithm>
#include<vector>
#define MAX 100001

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
   return pr[a]==pr[b]? 1:0;
}

void unionf(int a, int b){
    a = findf(a);
    b = findf(b);
    if(a>b) pr[a]=b;
    else pr[b]=a;
}

int main(){
    n=7;
    m=11;

    v.push_back(Edge(1,7,12));
    v.push_back(Edge(1,4,28));
    v.push_back(Edge(1,2,67));
    v.push_back(Edge(1,5,17));
    v.push_back(Edge(2,4,24));
    v.push_back(Edge(2,5,62));
    v.push_back(Edge(3,5,20));
    v.push_back(Edge(3,6,37));
    v.push_back(Edge(4,7,13));
    v.push_back(Edge(5,6,45));
    v.push_back(Edge(5,7,73));
    
    sort(v.begin(),v.end());

    for(int i=1;i<=n;i++){
        pr[i]=i;
    }
    for(int i=0; i<v.size();i++){
        int flag=check(v[i].node[0],v[i].node[1]);
        if(!flag){
            ans+=v[i].d;
            printf("%d   ",ans);
            unionf(v[i].node[0],v[i].node[1]);
        }
    }

    printf("%d",ans);



}
