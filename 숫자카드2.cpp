#include<bits/stdc++.h>

using namespace std;

vector<int> v;
int n,m;

int main(){
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int x;
		scanf("%d",&x);
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	scanf("%d",&m);
	for(int i=0; i<m; i++){
		int x;
		scanf("%d",&x);	
		int up = upper_bound(v.begin(),v.end(),x)-v.begin();
		int lo = lower_bound(v.begin(),v.end(),x)-v.begin();
		printf("%d ",up-lo);
	
	}
}
