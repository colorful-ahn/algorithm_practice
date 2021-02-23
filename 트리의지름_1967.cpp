#include<bits/stdc++.h>

using namespace std;

#define MAX 100001

int N;
int sum = 0;
int End;
vector <pair <int, int> > vec[MAX];
bool visited[MAX] = { false, };

void DFS(int start, int check_weight) {
	if (visited[start]) return;
	visited[start] = true;
	if (sum < check_weight) {
		sum = check_weight;
		End = start;
	}

	for (int i = 0; i < vec[start].size(); i++)
		DFS(vec[start][i].first, check_weight + vec[start][i].second);
}


int main() {
	scanf("%d",&N);

	int p,c,w;
	for (int i = 0; i < N; i++) {
		scanf("%d",&p);
		while(true){
			scanf("%d",&c);
			if(c==-1) break;
			scanf("%d",&w);
			vec[p].push_back(make_pair(c, w));
			vec[c].push_back(make_pair(p, w));
		}
		
	}
	DFS(1, 0);

	sum = 0;
	memset(visited, false, sizeof(visited));

	DFS(End, 0);
	printf("%d",sum);
	return 0;
}
