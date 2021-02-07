#include<bits/stdc++.h>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int> > pq;

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int x;
		scanf("%d",&x);
		pq.push(x);
	}
	for(int i=0; i<n; i++){
		printf("%d\n",pq.top());
		pq.pop();
	}
}
