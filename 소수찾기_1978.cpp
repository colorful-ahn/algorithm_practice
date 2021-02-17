#include<bits/stdc++.h>

using namespace std;

int n;
int arr[1001];
vector<int> v;
int result=0;

void so(){
	arr[1]=0;
	v.push_back(2);
	v.push_back(3);
	for(int j=2; j<1001; j++){
		for(int i=j+1; i<1001; i++){
		if(arr[i]==0) continue;
		if(arr[i]%j==0) arr[i]=0;
		}
	}
	for(int i=4; i<1001; i++){
		if(arr[i]!=0) v.push_back(arr[i]);
	}
}

int main(){
	scanf("%d",&n);
	for(int i=1; i<1001; i++){
		arr[i]=i;
	}
	so();
	while(n-->0){
		int x;
		scanf("%d",&x);
		for(int i=0; i<v.size();i++){
			if(x==v[i]) result++;
		}
	}
	printf("%d",result);
	
}
