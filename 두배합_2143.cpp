#include<bits/stdc++.h>

#define MAX 1000001
 
using namespace std; 
 
int t,n,m;
int narr[MAX];
int marr[MAX];
vector<long long> nv;
vector<long long> mv;

int main(){
	
	long long count=0;
	
	scanf("%d",&t);
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		int x;
		scanf("%d",&x);
		narr[i]=x;
	}
	scanf("%d",&m);
	for(int i=0; i<m; i++){
		int x;
		scanf("%d",&x);
		marr[i]=x;
	}
	for(int i=0; i<n; i++){
		nv.push_back(narr[i]);
		long long sum=narr[i];
		for(int j=i+1; j<n; j++){
			sum += narr[j];
			nv.push_back(sum);
		}
	}
	for(int i=0; i<m; i++){
		mv.push_back(marr[i]);
		long long sum=marr[i];
		for(int j=i+1; j<m; j++){
			sum += marr[j];
			mv.push_back(sum);
			
			
		}
	}
	
	sort(mv.begin(),mv.end());


	for(int i=0; i<nv.size();i++){
		long long target = t - nv[i];
		int hi = upper_bound(mv.begin(),mv.end(),target)-mv.begin();
		int lo = lower_bound(mv.begin(),mv.end(),target)-mv.begin();
		count += (hi-lo);
		
	}
	printf("%lld",count);	
}
