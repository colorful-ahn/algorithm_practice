#include<iostream>
#include<vector>
#include<queue>

using namespace std;

void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
}

int number = 6;
int INF = 1000000000;

vector<pair <int, int> > v[7];
int d[7];

void dijkstra(int s){
    d[s]=0;
    priority_queue<pair < int, int > > pq;
    pq.push(make_pair(s,0));
    //가까운 순서대로 처리
    while(!pq.empty()){
        //연결된 노드
        int cur = pq.top().first;
        // 짧은 것이 먼저 오도록 음수화 함.
        int dis = -pq.top().second;
        //cur은 현재 보고있는 친구
        pq.pop();
        //최단 거리가 아닌 경우 skip
        if(d[cur]<dis) continue;
        for(int i=0; i<v[cur].size();i++){
            int nxt = v[cur][i].first;
            int nxtd = dis + v[cur][i].second;
            if(nxtd < d[nxt]){
                d[nxt] = nxtd;
                pq.push(make_pair(nxt,-nxtd));
            }
        }
    }
}

int main(){

   for(int i=1; i<=number; i++){
       d[i]=INF;
   }

   v[1].push_back(make_pair(2,2));
   v[1].push_back(make_pair(3,5));
   v[1].push_back(make_pair(4,1));

   v[2].push_back(make_pair(1,2));
   v[2].push_back(make_pair(3,2));
   v[2].push_back(make_pair(4,2));

   v[3].push_back(make_pair(1,5));
   v[3].push_back(make_pair(2,3));
   v[3].push_back(make_pair(4,3));
   v[3].push_back(make_pair(5,1));
   v[3].push_back(make_pair(6,5));

   v[4].push_back(make_pair(1,1));
   v[4].push_back(make_pair(2,2));
   v[4].push_back(make_pair(3,3));
   v[4].push_back(make_pair(5,1));

   v[5].push_back(make_pair(3,1));
   v[5].push_back(make_pair(4,1));
   v[5].push_back(make_pair(6,2));

   v[6].push_back(make_pair(3,5));
   v[6].push_back(make_pair(5,2));

   dijkstra(1);

   for(int i=1; i<=number; i++){
       cout << d[i] << " ";
   }

}