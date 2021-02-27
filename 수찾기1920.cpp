#include<bits/stdc++.h>

using namespace std;

int n,m;
vector<int> v;

void search(int n, int ans){
	int s=0;
	int e=n-1;
	
	
	while(e-s>=0){
		int mid = (s+e)/2;
		if(v[mid]>ans){
			e = mid-1;
		}else if(v[mid]<ans){
			s = mid+1;
		}else{
			printf("1\n");
			return;
		}
	}
	printf("0\n");
	return;
	
}


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
		if(x < v[0] || x > v[n-1]) printf("0\n");
		else{
			search(n,x);
		}
	}
}
