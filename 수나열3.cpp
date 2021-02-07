#include <bits/stdc++.h>

using namespace std;

int n;
int v[10001];

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int x;
		scanf("%d",&x);
		v[x]++;
	}
	for(int i=1; i<=10000; i++){
			for(int j=0; j<v[i]; j++){
			printf("%d\n",i);	
		}	
	}
}
