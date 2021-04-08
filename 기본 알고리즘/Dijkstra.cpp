#include<iostream>

using namespace std;



    int number=6;
    int INF = 1000000000;

    //예시용 그래프
    int a[6][6]={
        {0,2,5,1,INF,INF},
        {2,0,3,2,INF,INF},
        {5,3,0,3,1,5},
        {1,2,3,0,1,INF},
        {INF,INF,1,1,0,2},
        {INF,INF,5,INF,2,0},

    };
    bool visited[6]={false,}; // 방문한 노드
    int d[6];   //최단 거리

    //가장 최소 거리를 가지는 정점을 반환
    int getindex(){
        int min = INF;
        int idx = 0;
        for(int i=0; i<number; i++){
            if(d[i]<min && !visited[i]){
                min = d[i];
                idx=i;
            }
        }
        return idx;
    }

    //dijkstra
    void dijkstra(int s){
        for(int i=0; i< number; i++){
            d[i]=a[s][i];
        }
        visited[s]=true;
        for(int i=0; i< number-2; i++){
            int current = getindex();
            visited[current] = true;
            for(int j = 0; j< number; j++){
                if(!visited[j]){
                    if(d[current]+a[current][j] < d[j]){
                        d[j] = d[current] + a[current][j];
                    }
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
        dijkstra(0);
        for(int i=0; i<number; i++){
            cout << d[i] << " ";
        }
    }


