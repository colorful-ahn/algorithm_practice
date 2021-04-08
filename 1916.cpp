#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#define INF 100000001
using namespace std;

int n,m; // n은 노드 m은 간선
vector<pair < int, int > > v[1001];
int d[1001];

void dij(int s){
    priority_queue<pair < int, int> > pq;
    d[s]=0;
    pq.push(make_pair(s,0));
    while(!pq.empty()){
        int cur = pq.top().first;
        int dis = -pq.top().second;
        pq.pop();
        if(d[cur]<dis) continue;
        for(int i=0; i<v[cur].size(); i++){
            int nxt = v[cur][i].first;
            int nxtd = dis  + v[cur][i].second;
            if(nxtd<d[nxt]){
                d[nxt] = nxtd;
                pq.push(make_pair(nxt,-nxtd));
            }
        }
    }
    
    

}

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int main(){
    init();
    cin >> n;
    for(int i=1; i<=n; i++){
        d[i]=INF;
    }
    cin >> m;
    for(int i=0; i<m; i++){
        int a,b,c;
        cin >> a >> b >> c;
        v[a].push_back(make_pair(b,c));
    }
    int s,e;
    cin >> s >> e;
    dij(s);
    cout << d[e];


    


}