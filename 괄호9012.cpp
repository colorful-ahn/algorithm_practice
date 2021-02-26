#include<bits/stdc++.h>

using namespace std;


int t;
stack<char> s;

int main(){
	cin >> t;
	while(t-->0){
		string str;
		cin >> str;
		for(int i=0; i<str.size(); i++){
			if(str[i]=='(')	s.push(str[i]);	
			if(str[i]==')'){
				if(s.empty()) s.push(str[i]);
				if(s.top()=='(') s.pop();
				else s.push(str[i]);
			}
		} 
		if(s.empty()) printf("YES\n");
		else printf("NO\n");
		while(!s.empty()){
			s.pop();
		}
	}
}
