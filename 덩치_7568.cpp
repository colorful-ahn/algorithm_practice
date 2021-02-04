#include<bits/stdc++.h>
using namespace std;

int n;
vector <pair < int,int> > v;
int arr[50];

int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		v.push_back(make_pair(0,0));
		arr[i]=1;
	}
	for(int i=0; i<n; i++){
		int x,y;
		scanf("%d%d",&x,&y);
		v[i].first = x;
		v[i].second = y;
	}
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(v[i].first<v[j].first && v[i].second<v[j].second) arr[i]+=1;
			
		}
	}
	for(int i=0; i<n; i++){
		printf("%d ",arr[i]);
	}
}
