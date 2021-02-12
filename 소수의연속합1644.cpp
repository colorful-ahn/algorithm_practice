#include <bits/stdc++.h>
#define MAX 4000001
#define ll long long

using namespace std;

int n;
int arr[MAX];
bool visited[MAX];

vector<int> v;

int main(){
	for (ll i = 2; i < MAX; ++i){
	if(!visited[i]){
		v.push_back(i);
		for(ll j=2*i; j < MAX; j+=i)
			visited[j] = true;
		}
	}	
	scanf("%d",&n);
	int sum=0, count=0, s=0, e=0;
	while(true){
		if(sum>=n){
			sum-=v[s];
			s++;
		}
		else if(e ==v.size()) break;
		else{
			sum+=v[e];
			e++;
		}
		if(sum == n) count++;
	}
	printf("%d",count);
		
	
}
