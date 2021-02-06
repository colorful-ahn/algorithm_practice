#include<bits/stdc++.h>

using namespace std;

vector<int> v;
int n;

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int x;
		scanf("%d",&x);
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	for(int i=0; i<n; i++){
		printf("%d\n",v[i]);
	}
}
