#include<bits/stdc++.h>

using namespace std;

int n;
int arr[100001];
vector<char> result; 
stack<int> s;


int main(){
	scanf("%d",&n);
	int index = 0;
	for(int i=0; i<n; i++){
		scanf("%d",&arr[i]);
	}
	for(int i=1; i<=n; i++){
		s.push(i);
		result.push_back('+');
		
		while(!s.empty()){
			if(arr[index] == s.top()){
				s.pop();
				result.push_back('-');
				index++;
			}else break;
		}
		
	}
	if(s.empty()){
		for(int i=0; i<result.size(); i++) printf("%c\n",result[i]);
	}else{
		printf("NO");
	}
}
