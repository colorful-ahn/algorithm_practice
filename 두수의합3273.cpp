#include<bits/stdc++.h>

using namespace std;

int n,goal;
vector<int> v;

int main(){
	scanf("%d",&n); 
	//v.assign(n,0);
	for(int i=0; i<n; i++){
		int x;
		scanf("%d",&x);
		v.push_back(x);
	}
	
	scanf("%d",&goal);
	
	sort(v.begin(),v.end());
	int s,e,sum=0;
	s=0;
	e=n-1;
	while(1){
		if(v[s]+v[e]>goal){
			e--;
		}else if(v[s]+v[e]<goal){
			s++;
		}else{
			sum++;
			e--;
		}
		if(s==e) break;
	}
	printf("%d",sum);
}
