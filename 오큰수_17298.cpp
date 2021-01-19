#include<bits/stdc++.h>

using namespace std; 

int n;
stack<int> s;
int arr[1000001];
int ans[1000001];

int main(){
	scanf("%d",&n);
	for(int i=1; i<=n;i++){
		int x;
		scanf("%d",&x);
		arr[i] =x;
		
		
	}
	
	for(int i=1; i<=n; i++){
		if(s.empty()){
			s.push(i);
		}
			while(!s.empty()&&arr[s.top()]<arr[i]){
				ans[s.top()] = arr[i];
				s.pop();
			}
			s.push(i);
		}
	
	
	while(!s.empty()){
		ans[s.top()] = -1;
		s.pop();
		
	}
	for(int i=1; i<=n; i++){
		printf("%d ",ans[i]);
	}
}
