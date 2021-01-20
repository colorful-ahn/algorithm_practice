#include <bits/stdc++.h>
using namespace std; 

int n,m;
vector < pair < long long,long long > > v;
vector <pair < long long ,long long > > v1;


int main(){
	
	scanf("%d%d",&n,&m);
	v.assign(n,{0,0});
	for(int i=0; i<n; i++){
		scanf("%d",&v[i].first);
	}
	for(int i=0; i<n; i++){
		scanf("%d",&v[i].second);
	}
	
	for(int i=0; i<n;i++){
		long long mem_sum = v[i].first;
		long long cost_sum = v[i].second;
		v1.push_back({mem_sum,cost_sum});
		for(int j=i;j<n;j++){
			mem_sum += v[j].first;
			cost_sum += v[j].second;
			v1.push_back({mem_sum,cost_sum});
		}
	}	
	long long min = -1;
	for(int i=0;i<v1.size();i++){
		if(v1[i].first>=m){
			if(min==-1 || min>v1[i].second){
				min = v1[i].second;
			}
		}
	}
	printf("%d",min);
	
}
