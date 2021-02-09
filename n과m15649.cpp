#include<bits/stdc++.h>
using namespace std;


int n,m;
int arr[9];
bool visited[9];

void BT(int cnt){
	 if(cnt ==m){
	 	for(int i=0; i<m; i++){
	 		printf("%d ",arr[i]);
		 }
		 printf("\n");
		 return;
	 }
	 for(int i=1; i<=n; i++){
	 	if(!visited[i]){
	 		visited[i] = true;
	 		arr[cnt] = i;
	 		BT(cnt+1);
	 		visited[i] = false;
		 }
	 }
	
}

int main(){
	scanf("%d%d",&n,&m);
	BT(0);
	
	
}
