#include<bits/stdc++.h>

#define MAX 1001

using namespace std;

int map_[MAX][MAX];
int visited[MAX];
queue<int> q;
int n,m,v;   // n == ������ ����  m == ������ ���� v�� Ž���� ������ ��ȣ.
 


 

void BFS(int v){
	//ť���� ����
	visited[v]=1;
	q.push(v);
	// �������� ����?
	while(!q.empty()){
		v = q.front();
		q.pop();
		
		printf("%d ",v);
		for(int i=1; i<=n; i++){
			if(map_[v][i] && !visited[i]){
				q.push(i);
				visited[i] = 1;
			}
		}
	}
	//����� ���� ��ȸ 
	//  �� �� �ִ°�??
	// üũ��& ť�� ���� 
}

void DFS(int v){
	printf("%d ",v);
	//üũ��
	visited[v]=1;
	//�������� ����?
	for(int i=0; i<=n; i++){
		if(map_[v][i] && !visited[i]){
			DFS(i);
		}
	}
	//����� ���� ��ȸ
	// �� �� �ִ°�? 
	// ����. 
	
	
	//üũ�ƿ� 
}






int main(){
	scanf("%d %d %d",&n,&m,&v);
	
	memset(map_,0,sizeof(map_));
	memset(visited,0,sizeof(visited));
	
	for(int i=0; i<m; i++){
		int a,b;  					//������ ����, ����Ǿ������� 1�� ǥ������
		scanf("%d %d",&a,&b);
		map_[a][b] = 1;
		map_[b][a] = 1; 
	}
	
	DFS(v);
	printf("\n");
	
	memset(visited,0,sizeof(visited));
	BFS(v);
	printf("\n");
	
}
