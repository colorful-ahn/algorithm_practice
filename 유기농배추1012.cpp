// #include<cstdio>
// #include<string.h>

// #define MAX 50+1


// int t;
// int n,m,k;
// int arr[MAX][MAX];
// bool visited[MAX][MAX];
// int dp[MAX][MAX];
// int dx[4] = {0,0,1,-1};
// int dy[4] = {1,-1,0,0};
// int count =0;

// void DFS(int a, int b){
//     visited[a][b] = true;
    
//     for(int i=0; i<4; i++){
//         int xnxt = a+dx[i];
//         int ynxt = b+dy[i];
//         if(xnxt>n || xnxt <0 || ynxt >m || ynxt<0){
//             continue;
//         }
//         else if(!visited[xnxt][ynxt] && arr[xnxt][ynxt]==1){
//             DFS(xnxt,ynxt);
//         }
//     }
// }


// int main(){
//     memset(visited,false,sizeof(visited));

//     scanf("%d",&t);
//     for(int i=0; i<t; i++){
//         scanf("%d%d%d",&n,&m,&k);
//         for(int j=0; j<k;j++){
//             int x,y;
//             scanf("%d%d",&x,&y);
//             arr[x][y] = 1;
//         }
//         for(int ii=0; ii<n; ii++){
//             for(int jj=0; jj<m; jj++){
//                 if(!visited[ii][jj] && arr[ii][jj]==1){
//                     DFS(ii,jj);
//                     count +=1;
//                 }
//             }
//         }
//         printf("%d\n",count);
//         count=0;
//     }

// }
#include <iostream>
#include <string.h>
#define MAX 50+1
using namespace std;
 
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int M,N,K;
int arr[MAX][MAX]={0};
bool visited[MAX][MAX]={0};
 
void dfs(int y,int x){
    visited[y][x] =true;

    for(int i=0; i<4; i++){
        int ny=y+dy[i];
        int nx=x+dx[i];
        if(ny<0 || ny>=N || nx<0 || nx>=M)
            continue;
        if(arr[ny][nx] && !visited[ny][nx]){
            dfs(ny,nx);
        }
    }
}
 
int main(){
    int T,x,y;
    scanf("%d", &T);
    
    for(int testCase=0; testCase<T; testCase++){
        scanf("%d %d %d", &M,&N,&K);
        
        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));
        
        int ans=0; //지렁이 개수
        
        for(int i=0; i<K; i++){
            scanf("%d %d", &x,&y);
            arr[y][x]=1;
        }
        
        for(int i=0; i<N; i++)
            for(int j=0; j<M; j++)
                if(arr[i][j] && !visited[i][j]){
                    dfs(i,j);
                    ans++;
                }
        printf("%d\n", ans);
    }
}