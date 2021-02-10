#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll arr[100001];

int main(){
	int n;
	scanf("%d",&n);
	for(int i=0; i<n; i++){
		ll x;
		scanf("%lld",&x);
		arr[i]=x;
	}
	sort(arr,arr+n);
	int l=0, r=n-1;
	ll val, al=arr[l],ar=arr[r],result=al+ar;
	while(l<r){
		val=arr[l]+arr[r];
		if(abs(result)>abs(val)){
			result =val;
			al = arr[l];
			ar=arr[r];
		}
		if(val<=0){
			l++;
		}else{
			r--;
		}
	}
	printf("%lld %lld",al,ar);
} 
