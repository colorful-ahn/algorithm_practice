#include<iostream>
#include<vector>
#include<stdio.h>

#define MAX 100001

using namespace std;

int n;
int arr[MAX][MAX];
int visited[MAX];
int input[MAX];
vector<int> v[MAX];
vector<int> sol;
int v_count=0;

void DFS(int jun, int a,int idx){
    
    
    if(!v[a].size()&&v_count!=n){
        DFS(jun,jun,idx);
    }else{
        sol.push_back(a);
        v_count++;
        for(int i=0; i<v[a].size(); i++){
            if(input[idx+1]==v[a][i]){
                DFS(a,v[a][i],idx+1);
            }
        }
    }
    
    
    

}

int main(){
    scanf("%d",&n);
    while(n-->1){
        int a,b;
        scanf("%d%d",&a,&b);
        arr[a][b]=1;
        arr[b][a]=1;
        v[a].push_back(b);
    }
    for(int i=0; i<n; i++){
        scanf("%d",&input[i]);
    }
    DFS(0,input[0],0);
    for(int i=0; i<sol.size();i++){
        printf("%d ",sol[i]);
    }


}