#include<bits/stdc++.h>

using namespace std;

queue<int> q;
int n;

int main(){
	
	scanf("%d",&n);
	for(int i=1; i<=n; i++){
		q.push(i);
	}
	while(q.size()>1){
		q.pop();
		q.push(q.front());
		q.pop();	
	} 
	printf("%d",q.front());
		
}
