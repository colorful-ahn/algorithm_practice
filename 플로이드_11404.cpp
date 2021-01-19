#include<bits/stdc++.h>


#define INF 20000000 

using namespace std;


struct Info {
	int b,c;
	Info (int bb, int cc){
		b = bb;
		c= cc;
		
	}
};


int n, m, dist[110][110];   // [i][j] i --> j�� ���� ��� 
int adj[110][110];


void floyd(){
	for(int j=1; j<=n; j++){	//�߰� 
		for(int i=1; i<=n; i++){	//���� 
			for(int k =1; k<=n; k++){ //�� 
				if(dist[i][j]==INF || dist[j][k] == INF) continue; 
				if(dist[i][j] + dist[j][k] < dist[i][k]){	//INF + INF �� �� ���� ����; 
					dist[i][k] = dist[i][j] + dist[j][k];
				}
			}
		}
	}
}

int main(){
	scanf("%d %d",&n,&m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(i!=j){
				dist[i][j]=INF;
			}
			
		}
	}
	for(int i=0; i<m; i++){
		int a, b,c;
		scanf("%d %d %d",&a,&b,&c);   // a-->b    c�� ���
		 
		if(c < dist[a][b]){
			dist[a][b]=c;
		}
	}
	//init
//	for(int i=1; i<=n; i++){
//		for(int j=1; j<=n; j++){
//			dist[i][j]=INF;
//		}
//	}
	floyd();
	
	for(int i=1; i<=n; i++){
		for(int j=1; j<=n; j++){
			if(dist[i][j]!=INF){
				printf("%d ",dist[i][j]);
			}else{
				printf("0 ");
			}
			
		}
		printf("\n");
	}
} 
