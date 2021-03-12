#include<bits/stdc++.h>

using namespace std;

bool visited[1000001];
vector<int> v;

int main(){
	int a,b;
	scanf("%d%d",&a,&b);
	for (int i = 2; i < 1000001; ++i){
	if(!visited[i]){
		v.push_back(i);
		for(int j=2*i; j < 1000001; j+=i)
			visited[j] = true;
		}
	}
	for(int i=0; i<v.size(); i++){
		if(v[i]>=a && v[i]<=b) printf("%d\n",v[i]);
	}
} 
