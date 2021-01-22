#include<bits/stdc++.h>

using namespace std;

int n;
stack<int> s;

int main(){
	scanf("%d",&n);
	for(int i=0;i<n; i++){
		int x;
		scanf("%d",&x);
		if(x==0){
			s.pop();
		}else{
			s.push(x);
		}
	}
	int sum=0;
	while(!s.empty()){
		sum+=s.top();
		s.pop();
	}
	printf("%d",sum);
} 
