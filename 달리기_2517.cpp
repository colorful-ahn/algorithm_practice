#include <bits/stdc++.h>

using namespace std;

int N;
vector<pair <int,int> > runner;
vector<pair <int,int> > temp;
vector<int> result;

void merge(int s, int m, int e){
	int p1 = s;
	int p2 = m + 1;
	int k = s;
	
	while(p1<=m && p2<=e){
		if(runner[p1].first>=runner[p2].first) 
		{
			temp[k++] = (runner[p1++]);
			
		}
		else{	
			int cnt=0;		
			cnt = (m-p1)+1;
			result[runner[p2].second] += cnt;		
			temp[k++] = runner[p2++];
		} 
	}
	
	
	while(p1<=m){
		temp[k++] = runner[p1++];
		
	}
	while(p2<=e){
		temp[k++] = runner[p2++];
		
	}
	for(int t=s;t<=e;++t){
		runner[t] = temp[t];
	}
}


void mergeSort(int s, int e){
	
	if(s < e){
		int mid = (s + e) / 2;
		mergeSort(s, mid);
		mergeSort(mid+1, e);
		merge(s, mid, e);
	}
}
int main(){
	

	scanf("%d",&N);
	runner.assign(N,{0,0});
	temp.assign(N,{0,0});
	result.assign(N+1,0);
	
	for(int i=0;i<N;i++){
		int x;
		scanf("%d",&x);
		runner[i]= {x,i+1};
	}
	
	mergeSort(0, N-1);
	
	//Ãâ·Â 
	for(int i=1;i<=N;i++){
		printf("%d ", i-result[i]);
	}
	
	return 0;
}

